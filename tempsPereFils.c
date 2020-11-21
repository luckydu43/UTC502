#include <stdio.h>
#include <sys/types.h>
#include <sys/times.h>

char buf[1024];
struct tms temps;

int main()
{int i;
nice(15);
for (i=0; i<1000000; i++);  /*  consommer du temps CPU */

if (fork() == 0)
	{ /* processus fils  */
		printf("caractéristiques du fils :\n");
		printf("\t\t uid = %d    gid = %d\n", getuid(), getgid());

		if (getcwd(buf, sizeof(buf)) != NULL) {
			printf("\t\t repertoire de travail: %s \n", buf);
		}

		//printf("\t\t repertoire de travail: %s \n",getcwd(buf, sizeof(buf)));

		printf("test fils fini\n");
		printf("\t\t nice:  %d\n", nice(0));
		times(&temps);
		printf("\t\t temps en mode utilisateur: %f\n", temps.tms_utime);
		printf("\t\t temps en mode noyau: %f\n", temps.tms_stime);
	}
else	{ /* processus père */
		sleep(10);	/* laisser le fils faire ses affichages  */
		printf("caracteristiques du pere :\n");
		if (getcwd(buf, sizeof(buf)) != NULL) {
			printf("\t\t repertoire de travail: %s \n", buf);
		}


		printf("\t\t uid = %d    gid = %d\n", getuid(), getgid());
		//printf("\t\t repertoire de travail: %s\n",getcwd(buf, 1024));
		printf("\t\t nice:  %d\n", nice(0));
		times(&temps);
		printf("\t\t temps en mode utilisateur: %f\n", temps.tms_utime);
		printf("\t\t temps en mode noyau: %f\n", temps.tms_stime);
	}
return 0;
}
