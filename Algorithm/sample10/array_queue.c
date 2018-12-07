/* array_queue.c */

#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 10

typedef struct array_queue {
    T elements[QUEUE_SIZE];
    int front;
    int rear;
} array_queue;

QUEUE queue_construct() {
    array_queue* a_queue = (array_queue*)malloc(sizeof(array_queue));
    a_queue->front = 0;
    a_queue->rear = 0;

    return (QUEUE)a_queue;
}

void queue_free(QUEUE queue) {
    array_queue* a_queue = (array_queue*)queue;
    if(a_queue == NULL) {
        return;
    }
    free(a_queue);
}

T queue_front(QUEUE queue) {
    array_queue* a_queue = (array_queue*)queue;
    if((a_queue == NULL) || (a_queue->front == a_queue->rear)) {
        return 0;
    }
    return a_queue->elements[a_queue->front];
}

T queue_dequeue(QUEUE queue) {
    array_queue* a_queue = (array_queue*)queue;
    if((a_queue == NULL) || (a_queue->front == a_queue->rear)) {
        return 0;
    }
    T result = a_queue->elements[a_queue->front];
    a_queue->front = (a_queue->front + 1) % QUEUE_SIZE;
    return result;
}

void queue_enqueue(QUEUE queue, T value) {
    array_queue* a_queue = (array_queue*)queue;
    if((a_queue == NULL) || ((a_queue->front - 1 - a_queue->rear) % QUEUE_SIZE == 0)) {
        return;
    }
    a_queue->elements[a_queue->rear] = value;
    a_queue->rear = (a_queue->rear + 1) % QUEUE_SIZE;
}

int queue_empty(QUEUE queue) {
    array_queue* a_queue = (array_queue*)queue;
    return (a_queue == NULL) || (a_queue->front == a_queue->rear);
}

T queue_popback(QUEUE queue) {
    array_queue* a_queue = (array_queue*)queue;
    if((a_queue == NULL) || (a_queue->front == a_queue->rear)) {
        return 0;
    }
    a_queue->rear = (a_queue->rear - 1) % QUEUE_SIZE;
    return a_queue->elements[a_queue->rear];
}

void queue_pushfront(QUEUE queue, T value) {
    array_queue* a_queue = (array_queue*)queue;
    if((a_queue == NULL) || ((a_queue->front - 1 - a_queue->rear) % QUEUE_SIZE == 0)) {
        return;
    }
    a_queue->front = (a_queue->front - 1) % QUEUE_SIZE;
    a_queue->elements[a_queue->front] = value;
}