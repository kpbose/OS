#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t w;    // write access
sem_t m;    // mutex
int rc=0;   // readers count

int writersCount;
int readersCount;
pthread_t writersThread[10], readersThread[10];
int writeCount[10], readCount[10];
int i;

void *writer(void *i) {
    int a = *((int *) i);

    sem_wait(&w);   // P(w)
    printf("Writer %d writes to DB.\n",a+1);
    writeCount[a+1]++;  
    sem_post(&w);   // V(w)

    free(i);
}
void *reader(void *i) {
    int a = *((int *) i);

    sem_wait(&m);   // P(m)
    rc++;
    if (rc == 1) {
        sem_wait(&w);   // P(w)
    }
    sem_post(&m);   // V (m)

    printf("Reader %d reads from DB.\n",a+1);
    readCount[a+1]++;   

    sem_wait(&m);   // P(m)
    rc--;
    if (rc == 0) {
        sem_post(&w);   // V(w)
    }
    sem_post(&m);   // V(m)

    free(i);
}

int main() {
    sem_init(&w,0,1);
    sem_init(&m,0,1);

    printf("Enter count of writers:");
    scanf("%d",&writersCount);
    printf("Enter count of readers:");
    scanf("%d",&readersCount);

    for (i=0; i<readersCount; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&readersThread[i], NULL, reader, arg);
    }
    for (i=0; i<writersCount; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&writersThread[i], NULL, writer, arg);
    }
    for (i=0; i<writersCount; i++) {
        pthread_join(writersThread[i], NULL);
    }   
    for (i=0; i<readersCount; i++) {
        pthread_join(readersThread[i], NULL);
    }

    printf("--------------\n");
    for (i=0; i<readersCount; i++) {
        printf("Reader %d read %d times\n",i+1,readCount[i+1]);
    }

    for (i=0; i<writersCount; i++) {
        printf("Writer %d wrote %d times\n",i+1,writeCount[i+1]);
    }

    sem_destroy(&w);
    sem_destroy(&m);
    return 0;
}
