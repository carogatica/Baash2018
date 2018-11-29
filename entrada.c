#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "entrada.h"

int contParametros(char* argv[] ,char* cadena){
	int contador=0;

	argv[0] = strtok(cadena, " \n");

	for(contador=1; contador<50; contador++){
		argv[contador] = strtok (NULL, " \n");
		if(argv[contador]==NULL)
			break;
	}

	return contador;
}

char* getEntrada(char* comando){
	//char* comando=(char*) malloc(sizeof(char)*1024);
	strcpy(comando,"\n");
	fgets(comando,256,stdin);
	return comando;
}



