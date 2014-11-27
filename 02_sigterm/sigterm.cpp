#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//SIGTERM es una constante que vale 15.
//Este programa muestra el valor de SIGTERM

int main(){

   printf("%i\n", SIGTERM);

   return EXIT_SUCCESS;
}
