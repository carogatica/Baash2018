#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include "entrada.c"
#include "segundoPlano.c"
#include "busqueda.c"
#include "salida.c"
#include "pipe.c"

int main(int argc, char *argv[])
{
	char* comando1[25];
	char* comando2[25];
	char* comando = (char*) malloc(sizeof(char)*1024);
	char hostname [20];
	gethostname(hostname,20);
	char* user=getlogin();

	int bg;
	int flagPid;
	char* path[25];
	getPath(path);
	char ejecutable[256];

	pid_t pid;


	while(1){
		int pipe=0;
		int pipeok=0;
		int redirec=0;
		char fileName[100];

		printf("%s@%s:%s$ ",  user, hostname, getenv("PWD"));

		//strcpy(comando,"\n");
		//fgets(comando,256,stdin);
		comando=getEntrada(comando);

//		printf("%s ", comando);

		argc=contParametros(argv,comando);

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
	//	printf("antes de buscar, %s %s\n", argv[0],path);
		buscarPath(argv[0], path, ejecutable);
		if(ejecutable[0]=='X')
			printf("Archivo no encontrado\n");
		else{
			pid=fork();
			if(pid<0){
				perror("Error al crear proceso Hijo");
				exit(1);
			}
			else if(pid==0){
				if(redirec==2)
					salida(fileName);
				else if(redirec==1)
					freopen(fileName,"r",stdin);
				else if(pipe==1){
					ejecutarPipe(comando1,comando2,path);
					pipeok=1;
				}
				if(!pipeok){
				//	printf("%s ", comando);
					execv(ejecutable,argv);
					perror(ejecutable);
					exit(1);
				}
			}
			else 
				flagPid=-1;
			if(bg)
				waitpid(pid,&flagPid,WNOHANG);
			else
				waitpid(pid,&flagPid,0);
		}

	}

	liberarPipe(comando1,comando2);
	free(comando);
	return 0;
}

