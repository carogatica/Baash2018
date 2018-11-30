#include "salida.h"

void salida(char archivo[]){
	int fid, flag, ok;
	flag=O_WRONLY|O_CREAT|O_TRUNC;
	ok=S_IWUSR|S_IRUSR;

	fid=open(archivo, flag, ok);
	if(fid<0){
		perror("open");
		exit(1);
	}
	close(STDOUT_FILENO);
	if(dup(fid)<0){
		perror("dup");
		exit(1);
	}
	close(fid);
}