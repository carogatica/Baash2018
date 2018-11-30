#ifndef _PIPE_H
#define _PIPE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "busqueda.h"

int check(char* argv[], char* comando1[], char* comando2[]);
int redireccion(char* argv[], char fileName[]);
void ejecutarPipe(char* comando1[], char* comando2[], char* path[]);
void liberarPipe( char* comando1[], char* comando2[]);


#endif