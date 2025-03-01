#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void *task1(void *arg) {
    if (pthread_mutex_trylock(&lock1) == 0) {
        printf("Task 1 acquired lock1\n");
        sleep(1);
        if (pthread_mutex_trylock(&lock2) == 0) {
            printf("Task 1 acquired lock2\n");
            pthread_mutex_unlock(&lock2);
        }
        pthread_mutex_unlock(&lock1);
    } else {
        printf("Task 1 could not acquire lock1, avoiding deadlock\n");
    }
    return NULL;
}

void *task2(void *arg) {
    if (pthread_mutex_trylock(&lock2) == 0) {
        printf("Task 2 acquired lock2\n");
        sleep(1);
        if (pthread_mutex_trylock(&lock1) == 0) {
            printf("Task 2 acquired lock1\n");
            pthread_mutex_unlock(&lock1);
        }
        pthread_mutex_unlock(&lock2);
    } else {
        printf("Task 2 could not acquire lock2, avoiding deadlock\n");
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    return 0;
}
