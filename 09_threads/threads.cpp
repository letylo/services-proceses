#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>

struct Tnumero{
    int num;
    int num2;
    int result;
    int sig;
};


void* suma(void* puntero){
     
    Tnumero sumar;
    Tnumero resultado;
    Tnumero restar;
    Tnumero signal;
    resultado.result = 0;

    while(resultado.result < 10000){
    sumar.num = rand() % 5;
    resultado.result += sumar.num;
    restar.num2 = rand() % 4;
    resultado.result -= restar.num2;
    printf("\nLa resta es %i", resultado.result);
    printf("\nLa suma es %i", resultado.result);
    }
     
    if (resultado.result == 10000)
	printf("El resultado ha llegado a 10000\n");
}

int main(){

    pthread_t hilo;
    Tnumero resultado;

    pthread_create(&hilo, NULL, &suma, NULL);
    pthread_join(hilo, NULL);
    sigaction(SIGINT, &suma, NULL);  
    return 0;
}

