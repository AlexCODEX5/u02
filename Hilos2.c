#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#define SIZE 30

void *lector(void *arg);
char buffer[SIZE];

void *lector(void *arg){
    pthread_t tid; char buf[5];

    tid = pthread_self();
    fprintf(stderr,"El ID de este hilo es: %x\n",(unsigned)tid);
    fprintf(stderr,"El contenido del buffer es: %s\n",buffer);
    sprintf(buf," %x ",(unsigned)tid);
    strcat(buffer,buf);
    pthread_exit(NULL);
}

int main(int argc, char *args[]){
    pthread_t tid1,tid2;
    strcpy(buffer,"Esto es un mensaje compartido");
    if (pthread_create(&tid1, NULL,lector,NULL))
    {
        perror("Error en pthread_create");
        exit(1);
    }
    if (pthread_create(&tid2,NULL,lector,NULL))
    {
        perror("Error en pthread_create");
        exit(1);
    }
    if (pthread_join(tid1,NULL))
    {
        printf("Pthread_join Error");fflush(stdout);
        exit(1);
    }
    if (pthread_join(tid2,NULL))
    {
        printf("Pthread_join Error");fflush(stdout);
        exit(1);
    }
    fprintf(stderr,"El hilo principal imprime el buffer %s\n",buffer);
    return 0;
}