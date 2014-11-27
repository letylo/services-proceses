#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STRLEN 0x20

const char *program[] = {
   "firefox",
   "gedit",
   "nautilus",
   "cat",
   NULL //valor centinela, que indica la terminacion de la lista de palabras.
};

void spawn(const char *program){

    int child = 0;    
    child = fork();
    if (child){
        //Parent code
    }else {
        //Child code
        execlp(program, program, "--version", NULL); //Te dice la version del programa elegido de la lista
        fprintf(stderr, "%s didn't start properly.\n", program);
        abort();
    }
}
//Despues del exec el hijo se convierte en el programa que se ha ejecutado (firefox, nautilus, gedit) y el padre es menu.cpp

int show_menu(){
   int option;

   system("clear");
   printf("Opciones:\n\n");
   for (int op=0; program[op]; op++)
       printf("\t%i. - %s\n", op + 1, program[op]);
   printf("\n\tSu opcion: ");
   scanf(" %i", &option);  
   
   return option -1;
}

int  main(int argc, char *argv[]){
 
   int option;
   option = show_menu();
   printf("\nSe ha arrancado: %s\n\n", program[option]);
   spawn(program[option]);

}
