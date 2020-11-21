 #include <stdio.h> 
 #include <stdlib.h> 
 int main(int argc, char *argv[], char *envp[]) 
 { 
	 int k; 
	 printf("Appel avec %d parametres\n",argc); 
	 printf("Le nom de la commande est %s\n",argv[0]); 
	 printf("Le nom de la commande est %s\n",argv[1]); 
	 
	printf("Les arguments de la commande sont les suivants : "); 
	 for (k=1;k<argc;k++)  printf("%d%s  ",k,argv[k]); 
	 printf("\n Les variables d'environnement sont :\n"); 
	 for(k=0;envp[k]!=NULL;k++)  printf("%s\n",envp[k]); 
	 exit(0); 
 }

