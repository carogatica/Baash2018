#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "teclado.c"
#include "pipe.c"
#include "segundoPlano.c"
#include "busqueda.c"

int main(int argc, char *argv[])
{
	char* comando1[25];
	char* comando2[25];
	char* comando = (char*) malloc(sizeof(char)*1024);
	char hostname [20];
	gethostname(hostname,20);

	char* user=getlogin();

	int bg;
	char* path[25];
	char* ejecutable[256];


	while(1){
		int pipe=0;
		int redirec=0;
		char fileName[100];

		printf("%s@%s:%s$ ",  user, hostname, getenv("PWD"));

		//strcpy(comando,"\n");
		//fgets(comando,256,stdin);
		comando=getEntrada(comando);

		//printf("%s ", comando);

		argc=teclado(argv,comando);

		if (!strcmp(comando,"\n")){
			printf("\n");
			continue;
		}
		else{

			if(!strcmp(comando,"exit")){
				return 0;
			}

			//printf("%s\n",comando);

			if (!strcmp(argv[0],"cd"))
			{
				chdir(argv[1]);
				continue;
			}
		}

		pipe=check(argv, comando1, comando2);
		redirec=redireccion(argv,fileName);

		bg=checkBG(argv);
		if(bg){
			argv[argc-1] = NULL;
			argv--;
		}

		buscarpath(argv, path, ejecutable);
	}

	liberarPipe(comando1,comando2);
	free(comando);
	return 0;
}

