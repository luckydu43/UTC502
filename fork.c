#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main () {
	pid_t pid; // ON peut ausi déclarer int pid;
	switch (pid=fork()) {
		case -1: perror("creation de processus");
			 exit(2);
		case 0: // Fils
			printf("je suis le fils %d, de père %d\n",
			getpid(),
			getppid());
			printf("fin du processus fils\n");
			exit(0);
		default: // Suite du père
			printf("je suis le processus %d, de père %d\n",
                        getpid(),       
                        getppid());
			sleep(1);
			printf("fin du processus père\n");
	}
}
