#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int contParametros(char* argv[] ,char* cadena);
char* getEntrada(char* comando);

#endif