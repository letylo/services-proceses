#include <pthread.h>
#include <stdio.h>


void* frase1 (void* puntero){

    while(1) 
    fputs("\n愛 和平 友誼 最初の 同情 精神\n", stderr );
    return NULL;
}

void* frase2 (void* puntero2){
    while(1)
	fputs("\nανοησία યુદ્ધ 憎む \n", stderr);
    return NULL;
}
int main(){

    pthread_t hilo;
    pthread_t hilo2;

    pthread_create (&hilo, NULL, &frase1, NULL);
    pthread_create (&hilo2, NULL, &frase2, NULL);
    while(1)
    fputs("\n第一 πνεύμα 日本 アルファ\n", stderr);
    return 0;
}
