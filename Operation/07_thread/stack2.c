#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

struct stack
{
    int buf[128];
    int count;
};
struct stack stk;
int tmp;

void stack_init(struct stack *stk)
{
    stk->count = 0;
}

void stack_push(struct stack *stk, int val)
{
    stk->buf[stk->count++] = val;
}

int stack_pop(struct stack *stk)
{
    if (stk->count <= 0)
    {
        fprintf(stderr, "ERROR: stack is empty\n");
        abort();
    }

    return stk->buf[--stk->count];
}

pthread_mutex_t mtx;
void *thread_entry(void *arg)
{
    pthread_mutex_lock(&mtx);
    for (int i = 0; i < 100000; i++)
    {
        stack_push(&stk, i);
        printf("%d\n", stack_pop(&stk));
        // tmp = stack_pop(&stk);
    }
    pthread_mutex_unlock(&mtx);

    return NULL;
}

int main(int argc, char *argv[])
{
    stack_init(&stk);

    pthread_t tid1, tid2;
    void *ret;
    int er;

    er = pthread_mutex_init(&mtx, NULL);
    if (er != 0)
        goto error;
    er = pthread_create(&tid1, NULL, thread_entry, NULL);
    if (er != 0)
        goto error;
    er = pthread_create(&tid2, NULL, thread_entry, NULL);
    if (er != 0)
        goto error;

    pthread_join(tid1, &ret);
    pthread_join(tid2, &ret);

    printf("%d\n", tmp);

    return 0;

error:
    fprintf(stderr, "ERROR\n");
    return -1;
}
