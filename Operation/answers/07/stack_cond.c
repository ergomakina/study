#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct stack {
    int buf[128];
    int count;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
};

void stack_init(struct stack* stk)
{
    stk->count = 0;
    pthread_mutex_init(&stk->mtx, NULL);
    pthread_cond_init(&stk->cond, NULL);
}

void stack_push(struct stack* stk, int val)
{
    pthread_mutex_lock(&stk->mtx);
    stk->buf[stk->count++] = val;
    pthread_cond_broadcast(&stk->cond);
    pthread_mutex_unlock(&stk->mtx);
}

int stack_pop(struct stack* stk)
{
    int ret;
    
    pthread_mutex_lock(&stk->mtx);
    while (stk->count <= 0) {
        pthread_cond_wait(&stk->cond, &stk->mtx);
    }

    ret = stk->buf[--stk->count];
    pthread_mutex_unlock(&stk->mtx);
    
    return ret;
}


void* push_thread_entry(void* arg)
{
    unsigned int r = 1000000 + time(NULL);
    struct stack* s = (struct stack*)arg;
    int i;
    
    for (i = 0; i < 100; i++) {
        stack_push(s, i);

        usleep(rand_r(&r) % 1000000);
    }

    return NULL;
}

void* pop_thread_entry(void* arg)
{
    unsigned int r = 2000000 + time(NULL);
    struct stack* s = (struct stack*)arg;
    int i;
    
    for (i = 0; i < 100; i++) {
        printf("popped: %d\n", stack_pop(s));

        usleep(rand_r(&r) % 1000000);
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    struct stack stk;
    pthread_t tid1, tid2;
    void* ret;
    int er;

    stack_init(&stk);

    er = pthread_create(&tid1, NULL, push_thread_entry, &stk);
    if (er != 0) goto error;
    er = pthread_create(&tid2, NULL, pop_thread_entry, &stk);
    if (er != 0) goto error;
    
    pthread_join(tid1, &ret);
    pthread_join(tid2, &ret);
    
    return 0;

 error:
    fprintf(stderr, "ERROR\n");
    return -1;
}
