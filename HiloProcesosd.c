#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*int pthread_create( pthread_t *tid,
                const pthread_attr_t *attr,
                void *(*star_routine)(void *),
                void *arg);

//void pthread_exit(void *value_ptr);

//int pthread_join(pthread_t thread, void **value_ptr);

//pthread_t pthread_self(void);
*/

void *print_message_function(void *ptr);
int main(int argc, char *args[]){
    pthread_t thread1, thread2;
    char *message1 = (char*)"Hilo 1";
    char *message2 = (char*)"Hilo 2";
    int i1, i2;

    i1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    i2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Hilo 1 retorna: %d \n", i1);
    printf("Hilo 2 retorna: %d \n", i2);

}

void *print_message_function(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s \n", message);
    return message;
}

