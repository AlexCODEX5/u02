#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    pid_t child = fork();
    if(child == 0)
    {
        /* soy hijo*/
        printf("soy el (%d, hijo de %d) \n", getpid(), getppid());
    }
    else 
    {   /*soy padre*/
        printf("SOY EL PADRE (%d, hijo de %d) \n", getpid(), getppid());
        return 0;
    }
}