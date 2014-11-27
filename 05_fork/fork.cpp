#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

   pid_t child_pid;
   //pid_t grandchild_pid;

   printf("El ID del proceso del programa es %i\n", (int) getpid() );
   printf("El ID del proceso padre es %i\n\n", (int) getppid() );

   for(int i=0; i<2; i++){
   child_pid = fork();
   printf("El child_pid es %i\n", (int) child_pid);
   }
       
   //child_pid = fork();
   //printf("El grandchild_pid es %i\n", (int) grandchild_pid);
}

