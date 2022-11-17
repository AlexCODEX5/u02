#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

float ThreadS = 0;
int INDEX = 0;

float *suma(void *numSum){
    //float *fnumOps = (float*)numOps;
      
    while (INDEX != 10)
    {
        ThreadS += ((float *)numSum)[INDEX++];
        printf("Suma total: %.3f\n", ThreadS);
    }
    pthread_exit(NULL);
    
    return &ThreadS;  
}

int main(int argc, char args[]){
    int NUM_THREADS, errc;
    float numArgs[10];
    char *hilos;
    pthread_t *ThreadSuma;
    printf("Numero de hilos: ");
    scanf("%i[^\n]", &NUM_THREADS);
    printf("Numero de hilos: %i\n", NUM_THREADS);
    //NUM_THREADS = atoi(hilos);
    //numArgs = (float*) malloc(10);
    ThreadSuma = (pthread_t*) malloc(NUM_THREADS);
    printf("Numero de hilos: %i\n", NUM_THREADS);
    for (unsigned i = 0; i < 10; i++)
    {
        printf("Insertar numero a la fila: ");
        scanf("%f", &numArgs[i]);
        //numArgs[i] = atof(hilos);
        printf("Numero #%i: %.3f \n", i+1, numArgs[i]);
    }   

    printf("\n");

    for (unsigned i = 0; i < NUM_THREADS; i++)
    {
        errc = pthread_create(&ThreadSuma[i], NULL, (void *) suma, (void*) &numArgs[i]);
        if (errc != 0)
        {
            printf("pthread_create ERROR; de pthread_create() es %d\n", errc);
            //return -1;
            exit(-1);
        }
        // valor MAXIMO 10
        
    }
    printf("Suma total: %.3f\n", ThreadS);
    pthread_exit(NULL);
}
