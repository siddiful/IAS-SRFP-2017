// Author: Siddharth Shukla
// Parallelized implementation (using pthreads) of finding the solution of the PRODUCER-CONSUMER PROBLEM using SEMAPHORES.


#include <stdio.h>
#include<stdlib.h> 
#include <sys/types.h>
#include<pthread.h>
#include <semaphore.h>
#include <time.h>

sem_t mut;
sem_t empty;
sem_t full;
int buffer[200];
pthread_t ptd[20],ctd[20];
int cap,cntp,cntc,up,uc,bi=0,bo=0;

void *producer(void *arg){
int i,item,ID=pthread_self();
for(i=1;i<=cntp;i++){
item=1+(rand() % 500);
sem_wait(&empty);
sem_wait(&mut);
bi=(bi+1)%cap;

buffer[bi]=item;
time_t dur=time(NULL);
printf("%dth item: %d produced by thread %d at %s into buffer location %d\n",i,item,ID,asctime(gmtime(&dur)),bi);
sem_post(&mut);
sem_post(&full);
}
}

void *consumer(void *arg){
int i,item,ID=pthread_self();
for(i=1;i<=cntc;i++){
sem_wait(&full);
sem_wait(&mut);
item=buffer[bo+1];
bo=(bo+1)%cap;
time_t dur=time(NULL);
printf("%dth item: %d consumed by thread %d at %s from buffer location %d\n",i,buffer[bo],ID,asctime(gmtime(&dur)),bo);
sem_post(&mut);
sem_post(&empty);
}
}

int main(){
int i,np,nc;
printf("Enter capacity,np,nc,cntp,cntc,up,uc: ");
scanf("%d %d %d %d %d %d %d",&cap,&np,&nc,&cntp,&cntc,&up,&uc);
sem_init(&mut,0,1);sem_init(&empty,0,cap);sem_init(&full,0,0);
for(i=1;i<=np;i++)
pthread_create(&ptd[i],NULL,producer,NULL);
for(i=1;i<=nc;i++)
pthread_create(&ctd[i],NULL,consumer,NULL);
for(i=1;i<=np;i++)
pthread_join(ptd[i],NULL);
for(i=1;i<=nc;i++)
pthread_join(ctd[i],NULL);
exit(0);}

