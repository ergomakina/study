#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

int tmp;

struct stack
{
    int buf[128];
    int count;
};

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

void *thread_entry(void *stk)
{
    int i;

    for (i = 0; i < 100000; i++)
    {
        stack_push(stk, i);
        printf("%d\n", stack_pop(stk));
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    struct stack stk;
    int er, i;
    void *retval;
    pthread_t tid[2];

    stack_init(&stk);

    for (i = 0; i < 2; i++)
    {
        er = pthread_create(&tid[i], NULL, thread_entry, &stk);
        if (er != 0)
        {
            fprintf(stderr, "ERROR: pthread_create failed\n");
            return -1;
        }
    }

    for (i = 0; i < 2; i++)
    {
        er = pthread_join(tid[i], &retval);
        if (er != 0)
        {
            fprintf(stderr, "ERROR: pthread_join failed\n");
            return -1;
        }
    }

    printf("%d\n", tmp);

    return 0;
}
