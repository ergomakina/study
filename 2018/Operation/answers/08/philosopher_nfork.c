#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

#define PHILOSOPHERS 5
#define DAYS 10000

static const char* names[] = {
    "Enryo", "Socrates", "Platon", "Aristoteles", "Kant"
};

int nfork;
bool fork_up[PHILOSOPHERS];
pthread_mutex_t mtx;
pthread_cond_t cond;

pthread_t philosophers[PHILOSOPHERS];

static void eat(int phil, int fork1, int fork2)
{
    printf("%s: \"Yummy!\"\n", names[phil]);
}


static void acquire_fork(int fork, bool first)
{
    pthread_mutex_lock(&mtx);
    while (fork_up[fork] || (first && nfork >= 4)) {
        pthread_cond_wait(&cond, &mtx);
    }
    fork_up[fork] = true;
    nfork++;
    pthread_mutex_unlock(&mtx);
}

static void release_fork(int fork)
{
    pthread_mutex_lock(&mtx);
    fork_up[fork] = false;
    nfork--;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mtx);
}


void* philosopher_thread(void* arg)
{
    int phil = (int)(intptr_t)arg;
    unsigned int r = (phil << 16) + time(NULL);
    int left = phil;
    int right = (phil+1) % PHILOSOPHERS;
    int i;

    usleep(rand_r(&r) % 100000);

    for (i = 0; i < DAYS; i++) {
        /* Think for a while */
        usleep(rand_r(&r) % 100);
        
        /* Staring to eat */
        acquire_fork(left, true);
        printf("%s picked up fork on the left\n", names[phil]);
        acquire_fork(right, false);
        printf("%s picked up fork on the right\n", names[phil]);

        eat(phil, left, right);

        printf("%s returned fork on the right\n", names[phil]);
        release_fork(right);
        printf("%s returned fork on the left\n", names[phil]);
        release_fork(left);
    }

    return NULL;
}


int main()
{
    int er, i;
    void* ret;

    nfork = 0;
    memset(fork_up, 0, sizeof(fork_up));

    er = pthread_mutex_init(&mtx, NULL);
    if (er != 0) goto error;

    er = pthread_cond_init(&cond, NULL);
    if (er != 0) goto error;

    for (i = 0; i < PHILOSOPHERS; i++) {
        er = pthread_create(&philosophers[i], NULL, philosopher_thread, (void*)(intptr_t)i);
        if (er != 0) goto error;
    }
    for (i = 0; i < PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], &ret);
    }
    printf("finished\n");
    return 0;

 error:
    fprintf(stderr, "ERROR\n");
    return -1;
}
