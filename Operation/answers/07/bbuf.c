#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define BBUF_SIZE 10

typedef struct {
    char buf[BBUF_SIZE];
    int front;
    int count;
    pthread_mutex_t mtx;
    pthread_cond_t cond_notfull;
    pthread_cond_t cond_notempty;
} bbuf;

void bb_init(bbuf* b)
{
    b->count = b->front = 0;
    pthread_mutex_init(&b->mtx, NULL);
    pthread_cond_init(&b->cond_notfull, NULL);
    pthread_cond_init(&b->cond_notempty, NULL);
}

void bb_put(bbuf* b, char c)
{
    bool wasempty;
    
    pthread_mutex_lock(&b->mtx);
    
    while (b->count >= BBUF_SIZE) {
        pthread_cond_wait(&b->cond_notfull, &b->mtx);
    }

    wasempty = (b->count <= 0);
    b->buf[(b->front + b->count++) % BBUF_SIZE] = c;
    if (wasempty) pthread_cond_broadcast(&b->cond_notempty);
    
    pthread_mutex_unlock(&b->mtx);
}

char bb_get(bbuf* b)
{
    bool wasfull;
    char c;
    
    pthread_mutex_lock(&b->mtx);
    
    while (b->count <= 0) {
        pthread_cond_wait(&b->cond_notempty, &b->mtx);
    }

    wasfull = (b->count >= BBUF_SIZE);
    c = b->buf[b->front];
    b->front = (b->front + 1) % BBUF_SIZE;
    b->count--;
    if (wasfull) pthread_cond_broadcast(&b->cond_notfull);

    pthread_mutex_unlock(&b->mtx);
    
    return c;
}


void* put_thread_entry(void* arg)
{
    char* s = "Hi, my name is INIAD Taro!\n";
    unsigned int r = 1000000 + time(NULL);
    bbuf* b = (bbuf*)arg;
    int i;
    
    for (i = 0; i < strlen(s); i++) {
        bb_put(b, s[i]);

        usleep(rand_r(&r) % 1000000);
    }

    return NULL;
}

void* get_thread_entry(void* arg)
{
    unsigned int r = 2000000 + time(NULL);
    bbuf* b = (bbuf*)arg;
    char c;
    int i;
    
    for (i = 0;; i++) {
        c = bb_get(b);
        putchar(c);
        fflush(stdout);
        
        if (c == '\n') break;
        
        usleep(rand_r(&r) % 1000000);
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    bbuf b;
    pthread_t tid1, tid2;
    void* ret;
    int er;

    bb_init(&b);

    er = pthread_create(&tid1, NULL, put_thread_entry, &b);
    if (er != 0) goto error;
    er = pthread_create(&tid2, NULL, get_thread_entry, &b);
    if (er != 0) goto error;
    
    pthread_join(tid1, &ret);
    pthread_join(tid2, &ret);
    
    return 0;

 error:
    fprintf(stderr, "ERROR\n");
    return -1;
}
