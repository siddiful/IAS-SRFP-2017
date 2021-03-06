// Author: Siddharth Shukla
// Parallelized (using pthreads) implementation of finding the solutions of linear algebraic equations (of form AX=B) having upto 1000 variables using *-SEMIRING METHOD.


#include <bits/stdc++.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include<stdlib.h> 
#include <sys/types.h>
#define n 1000
#define ll int
using namespace std;
float X[2*n][n+1];

sem_t mut;
pthread_t ptd[n];
ll k;
void *soln(void *arg){
sem_wait(&mut);
float temp=(float)(1/(1-X[k][k]));
for(ll i=k+1;i<=n+k;i++)
for(ll j=k+1;j<=n;j++)
X[i][j]+=(X[i][k] * X[k][j] * temp);
sem_post(&mut);
k++;
}

int main(){
clock_t tStart = clock();
ll a[n][n],b[n][1];
int k=0,j=0,i;
for(ll i=0;i<1000000;i++){
a[j][k]=rand()%40;
k++;
if(k==1000){k=(k%1000);j++;}}
for(i=0;i<n;i++){
b[i][0]=rand()%50;}
for(i=0;i<2*n;i++){
for(j=0;j<=n;j++){
if(j<n && i<n){
if(i==j){
X[i][j]=1-a[i][j];}
else X[i][j]=(-a[i][j]);
}
else if(j==n && i<n)X[i][j]=b[i][0];
else{
if((i-j)==n)X[i][j]=1;
else X[i][j]=0;
}
}}
sem_init(&mut,0,1);
for(i=0;i<n;i++)
pthread_create(&ptd[i],NULL,soln,NULL);
for(i=0;i<n;i++)
pthread_join(ptd[i],NULL);
cout<<"\nValues of x are as follows: \n";
for(i=0;i<n;i++)
cout<<"x"<<i+1<<"= "<<X[i+n][n]<<"\n";
 printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
exit(0);}
