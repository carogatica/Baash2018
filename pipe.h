#ifndef _PIPE_H
#define _PIPE_H


int check(char* argv[], char* comando1[], char* comando2[]);
int redireccion(char* argv[], char fileName[]);
void liberarPipe( char* comando1[], char* comando2[]);


#endif