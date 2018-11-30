#ifndef _BUSQUEDA_H
#define _BUSQUEDA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void buscarPath(char* argv, char* path[], char* ejecutable);
void getPath (char* path[]);

#endif