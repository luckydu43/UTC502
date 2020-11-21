#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int n=1000;

void main(){
int k = 500;
printf("Adr de n chez le pere:  %p\n", &n);
printf("Adr de k chez le pere:  %p\n", &k);
printf("Valeurs de n et k chez le pere:%d %d\n", n, k);

switch(fork()){
case -1: {perror("erreur fork"); exit(2);}
case 0: /* processus fils */
	printf("Adr de n chez le fils : %p \n",&n);
	printf("Adr de k chez le fils : %p \n",&k);
	printf("Valeurs de n et de k chez le fils:  %d    %d\n", n, k);
	n++ ;   k++;         /*modif de n et k par le fils */
	printf("Nouvelles val de n et k chez le fils:%d %d\n", n, k);
	sleep(4);/*attend que le p�re modifie ses variables*/
	printf("Dernieres val de n et k chez le fils:%d %d\n", n, k);
	printf("Adr de n chez le fils:  %p\n", &n);
	printf("Adr de k chez le fils:  %p\n", &k);

	exit(0);

default:     /* processus p�re */
	sleep(2);/*attend que le fils modifie ses variables */
	printf("Valeurs de n et k chez le pere:%d %d\n",n, k);
	n *=3;  k *=3;     /*modif de n et k par le p�re */
	printf("Dernieres val de n et k chez le pere: %d %d\n", n, k);
	printf("Adr de n chez le pere:  %p\n", &n);
	printf("Adr de k chez le pere:  %p\n", &k);

	sleep(2); exit(0);
	}
}

