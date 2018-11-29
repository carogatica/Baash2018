#include "pipe.h"



int check(char* argv[], char* comando1[], char* comando2[]){
	int i1, i2, aux;

	for(i1=0;argv[i1]!=NULL;i1++){
		aux=strcmp("|",argv[i1]);

		if(aux==0)  //es un |
			break;

		comando1[i1]=(char*) malloc(strlen(argv[i1]+1)); //si no es |
		strcpy(comando1[i1],argv[i1]); //copia lo de argv en comando11
	}

	comando1[i1]='\0';

	if(argv[i1]==NULL)
		return 0;

	i1++;

	for(i2=0;argv[i1]!=NULL;i2++){
		if(argv[i1]==NULL)  //no hay ningun comando
			break;

		comando2[i2]=(char*) malloc(strlen(argv[i1]+1));
		strcpy(comando2[i2],argv[i1]); 
		i1++;
	}
	comando2[i2]='\0';

	return 1;
}

int redireccion(char* argv[], char fileName[]){
	int i=0;

	for(i=0;i<20;i++){
		if(argv[i] == NULL){
		fileName = NULL;
		return 0;
		}
		else if(!strcmp(argv[i],"<")){
			strcpy(fileName,argv[i+1]);
			argv[i]=NULL;
			argv[i+1]=NULL;
			return 1;
		}

		else if(!strcmp(argv[i],">")){
			strcpy(fileName,argv[i+1]);
			argv[i]=NULL;
			argv[i+1]=NULL;
			return 2;	
		}
	}
	return 0;
}

void ejecutarPipe(char* comando1[], char* comando2[], char* path[]){
	char ejecutable[256];
	int fd[2];
	pipe(fd);
	if(fork()==0){
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		buscarPath(comando1[1],path,ejecutable);
		execv(ejecutable,comando1);
		perror(ejecutable);
		exit(1);
	}
	else{
		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);
		buscarPath(comando2[0],path,ejecutable);
		execv(ejecutable,comando2);
		perror(ejecutable);
		exit(1);
	}
}

void liberarPipe( char* comando1[], char* comando2[]){
	for(int i=0;i<20;i++){
		free(comando1[i]);
		free(comando2[i]);
	}

	free(comando1);
	free(comando2);
	return;
}