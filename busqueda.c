void buscarPath(char* argv, char* path[], char* ejecutable){
	//char copiaArgv[100];
	//strcpy(copiaArgv,argv);

	char buscado[100]="";
	char* archivo;
	int listo;
	//path relativo
	if(argv[0]=='/' || (argv[0]=='.' && argv[1]=='.' && argv[2]=='/')){
		int flag=0;
		char* direc;
		char* next;

		if (argv[0]=='/')
			buscado[0]='/';

		direc=strtok(argv,"/"); 
		next=strtok(NULL,"/");

		if(next!=NULL)
			strcat(buscado,direc);
		else{
			next=direc;
			flag=1;
		}

		while((next!=NULL) && !flag){
			direc=next;
			next=strtok(NULL,"/");
			strcat(buscado,"/");

			if(next!=NULL)
				strcat(buscado,direc);
		}
		archivo=direc;
	}
	else if(argv[0]=='.' && argv[1]=='/'){
		getcwd(buscado,50);
		strcat(buscado,"/");
		archivo=strtok(argv,"/");
		archivo=strtok(NULL,"/");
	}
	//path absoluto
	else{
		int i;
		char aux[100];
		for(i = 0; i < 20; i++){
			if(path[i] == NULL)
				break;
			strcpy(aux,path[i]);
			strcat(aux,"/");
			strcat(aux,argv);
		//	printf("En busqueda, %s %s\n", aux,argv);
			listo=access(aux,F_OK); //si la request tuvo exito, retorna 0
			if(!listo){
				strcpy(ejecutable,aux);
				return;
			}
		}
	//	printf("En busqueda, %s %s\n", aux,argv);
		ejecutable[0]='X';  //Error, access=-1
		return;
	}

	//printf("En busqueda, %s %s\n", buscado,archivo);
	strcat(buscado,archivo);
	listo=access(buscado,F_OK);
	if(!listo)
		strcpy(ejecutable,buscado);
	else
		ejecutable[0]='X';
	return;
}

void getPath (char* path[])
{
	char * pPath = getenv ("PATH");
	int contadorPath;
	
	path[0] = strtok(pPath, ":");
	
	for(contadorPath = 1; contadorPath< 20; contadorPath++)
	{
		path[contadorPath] = strtok(NULL,":");		
		if (path[contadorPath] == NULL)
			break;
	}
	
	strtok(NULL,":");
	return;


}