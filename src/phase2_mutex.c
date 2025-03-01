#include <stdio.h>
#include <pthread.h>

int balance = 1000;
pthread_mutex_t lock;

void *withdraw(void *arg) {
    pthread_mutex_lock(&lock);
    if (balance >= 200) {
        balance -= 200;
        printf("Withdrawal successful. New balance: %d\n", balance);
    } else {
        printf("Insufficient funds.\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, withdraw, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
