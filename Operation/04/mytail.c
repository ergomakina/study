#include <stdio.h>

struct queue
{
    char data[125];
    int head;
    int tail;
};

void initialize(struct queue *q, int N)
{
    int i;

    q->head = 0;
    q->tail = 0;
    for (i = 0; i < N; ++i)
    {
        q->data[i] = ' ';
    }
}

void enqueue(struct queue *q, int item, int N)
{
    if (q->tail >= N)
    {
        printf("This queue is full! \n");
    }
    else
    {
        q->data[q->tail] = item;
        q->tail++;
    }
}

int dequeue(struct queue *q)
{
    int tmp;

    if (q->head == q->tail)
    {
        return -1;
    }
    else
    {
        tmp = q->data[q->head];
        q->head++;
        return tmp;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
