#include <stdio.h>
#include <unistd.h>

int main(){

   printf("El ID del proceso es %i\n", (int) getpid());
   printf("El ID del proceso padre es %i\n", (int) getppid());
   return 0;
}
