#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
    ++sigusr1_count;
}

int main()
{
    struct sigaction sa;            //Se declara sa del tipo struct sigaction
    memset (&sa, 0, sizeof (sa));   //memset pone un 0 en la direccion de memoria de sa tantas veces como casillas ocupe sa 
    sa.sa_handler = &handler;       //en el campo sa.sa_handler se asigna la direcion de memoria de la función handler
    sigaction (SIGUSR1, &sa, NULL); //sigaction llama a SIGUSR1, lo guarda en la dirección de memoria de sa,
                                    // y devuelve NULL

    printf("SIGUSR1 was raised %d times\n", sigusr1_count);
    return 0;
}
