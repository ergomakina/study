#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct stack {
    int buf[128];
    int count;
    pthread_mutex_t mtx;
};

void stack_init(struct stack* stk)
{
    stk->count = 0;
    pthread_mutex_init(&stk->mtx, NULL);
}

void stack_push(struct stack* stk, int val)
{
    pthread_mutex_lock(&stk->mtx);
    stk->buf[stk->count++] = val;
    pthread_mutex_unlock(&stk->mtx);
}

int stack_pop(struct stack* stk)
{
    int ret;
    
    if (stk->count <= 0) {
        fprintf(stderr, "ERROR: stack is empty\n");
        abort();
    }

    pthread_mutex_lock(&stk->mtx);
    ret = stk->buf[--stk->count];
    pthread_mutex_unlock(&stk->mtx);
    return ret;
}


void* thread_entry(void* arg)
{
    struct stack* s = (struct stack*)arg;
    int i;
    
    for (i = 0; i < 1000000; i++) {
        stack_push(s, i);
        //printf("%d\n", stack_pop(s));
        stack_pop(s);
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

    er = pthread_create(&tid1, NULL, thread_entry, &stk);
    if (er != 0) goto error;
    er = pthread_create(&tid2, NULL, thread_entry, &stk);
    if (er != 0) goto error;
    
    pthread_join(tid1, &ret);
    pthread_join(tid2, &ret);
    
    return 0;

 error:
    fprintf(stderr, "ERROR\n");
    return -1;
}
