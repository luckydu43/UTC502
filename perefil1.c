#include <stdio.h>
#include <unistd.h>

int main(void) {
	int PID;
	if ((PID = fork()) == 0) {
		//Processus fils
		printf("1ere partie du fils \n");
		printf("\t 2ème partie du fils \n");
		printf("\t\t 3ème partie du fils \n");
	} else if (PID > 0) {
		//Processus père
		printf("1ère partie du père \n");
		printf("\t2ème partie du père\n");
		printf("\t\t3ème partie du père\n");
	} else {
		perror ("Erreur dans Fork !!!!!");
	}
	return 0;
}
