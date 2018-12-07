/* queue.h */

typedef void* QUEUE;
typedef void* T;

QUEUE queue_construct();
void queue_free(QUEUE queue);

T queue_front(QUEUE queue);
T queue_dequeue(QUEUE queue);
void queue_enqueue(QUEUE queue, T value);
int queue_empty(QUEUE queue);
