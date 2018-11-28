int checkBG(char* argv[]){
	int i=0;

	while(argv[i]!=NULL)
		i++;

	if(!strcmp(argv[i-1],"&"))
		return 1;

	return 0;
}