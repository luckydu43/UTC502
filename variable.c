/* A compiler avec l'option -threads ou -lpthread selon les systèmes */
/* variable.c */

/* Utilisation de variables globales et de variables locales:
les variables globales sont accessibles par toutes les threads ; les variables locales sont implantees sur la pile propre a chaque thread et ne sont pas accessibles aux autres */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_t	pth_id[3];
int globale=0;

/* fonction executee par  chaque thread */
void *fonc_thread(void *num){
int k;
int locale=10;
for(k=0;k<3;k++){
   locale++;
   globale++;
   printf("Thread d'identite %d.%d: ",getpid(), pthread_self());
   printf("globale=%d, locale=%d\n",globale, locale);
   usleep(100000); /* pour simuler un traitement */ 
   }
}


void main(){
int i;
for(i=0;i<3; i++){
  pthread_create(pth_id+i, 0, fonc_thread,(void *) i);
}

 sleep(1); /* pour eviter que la thread initiale ne fasse exit avant que les autres ne soient terminees , ce qui les terminerait*/
}

