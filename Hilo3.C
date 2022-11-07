#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5
char *messages[NUM_THREADS];

void *printHello(void * threadid)
{
    long taskid;

    taskid= (long) threadid;
    printf("Thread %ld: %s\n", taskid, messages[taskid]);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    long taskids[NUM_THREADS];
    int rc, t;

    messages[0] = (char*)"English: Hello World!";
    messages[1] = (char*)"French: Bonjour,le monde!";
    messages[2] = (char*)"Spanish: Hola al mundo!";
    messages[3] = (char*)"Japan: Sekai e konnichiwan!";
    messages[4] = (char*)"German: Guten Tag. Welt!";

    for (t = 0; t < NUM_THREADS; t++)
    {
        taskids[t] = t;
        printf("Creando thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, printHello, (void *)taskids[t]);
        if(rc){
            printf("ERROR; de pthread_create() es %d\n", rc);
            exit(-1);
        }

    }
    //pthread_exit(NULL);
}