#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int server (int client_socket)
{
    while(1) {
	int length = 0;
	char* text;
	int quit = 0;

	//Leemos el texto del mensaje del socket,
	//si devuelve 0, y abajo en el main, el cliente cierra la conexion
	if( read (client_socket, &length, sizeof (length)) == 0)
	    return 0;

	//Asignar un buffer para contener el texto
	text = (char*) malloc (length);
	//Leer del socket, la varible text y lo imprimo
	read (client_socket, text, length);
	printf ("%s\n", text);
	//Si no es false quit devuelve 1
	if (!strcmp (text, "quit"))
	    quit = 1;
	//Libero la memoria
	free(text);
	if(quit)
	    return 1;
    }
}

int main (int argc, char* const argv[])
{
    const char* const socket_name = argv[1];
    int socket_fd;
    struct sockaddr_un name;
    int client_sent_quit_message;

    //Crear el socket
    socket_fd = socket (AF_UNIX, SOCK_STREAM, 0 );
    //Indicar que esto es un servidor
    name.sun_family = AF_UNIX;
    strcpy (name.sun_path, socket_name);
    //Le digo al  socket como se llama el fichero, en el que escribe el SO
    if (bind (socket_fd, (struct sockaddr *) &name, SUN_LEN(&name)) == -1)
	perror("bind"), exit(1);
    //El SO le deja 5 socket al servidor para que escuche
    if (listen (socket_fd, 5) == -1)
	perror("Listen"), exit(1);

    //Aceptar conexiones repetidamente, continuar hasta que un cliente
    //envie un mensage 'quitar'
    do {
	struct sockaddr_un client_name;
	socklen_t client_name_len = SUN_LEN(&client_name);
	int client_socket_fd;

	//El servidor escucha, y acepta una conexion
	client_socket_fd = accept (socket_fd, (struct sockaddr *) &client_name, &client_name_len);
	if (client_socket_fd == -1)
	    perror("Client"), exit(1);
	//Abre la conexion para recibir
	client_sent_quit_message = server (client_socket_fd);
	//Cerrar el extremo de la conexion
	close (client_socket_fd);
    }
    while(!client_sent_quit_message);

    //Eliminar el archivo del socket
    close (socket_fd);
    unlink (socket_name);

    return EXIT_SUCCESS;
}
