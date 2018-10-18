#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <Pipe.c>

int teclado(char* argv[] ,char* cadena);

int main(int argc, char *argv[])
{
	char* argv1[25];
	char* argv2[25];

	char comando[250];
	
	int pipeOk=0;

	while(1){
		strcpy(comando, "\n");

		printf("%s@%s:%s$ ",  getenv("USER"), getenv("HOSTNAME"), getenv("PWD"));

		fgets(comando,256,stdin);

		argc=teclado(argv,comando);

		if(!strcmp(comando,"exit")){
			return 0;
		}

		//printf("%s\n",comando);

		if (!strcmp(argv[0],"cd"))
		{
			chdir(argv[1]);
			continue;
		}

		pipiOk=checkPipe(argv,argv1,argv2);


	}
	return 0;
}

int teclado(char* argv[] ,char* cadena){
	int contador=0;

	argv[0] = strtok(cadena, " \n");

	for(contador=1; contador<50; contador++){
		argv[contador] = strtok (NULL, " \n");
		if(argv[contador]==NULL)
			break;
	}

	return contador;
}