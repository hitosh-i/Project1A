#include <stdio.h>
#include <pthread.h>

void *print_message(void *arg) {
    printf("Hello from thread %ld\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (long i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, print_message, (void *)i);

    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
