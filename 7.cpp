// Author: Siddharth Shukla
// Modified parallelized (using pthreads) implementation (better running time) of finding the solutions of linear algebraic equations (of form AX=B) having upto 1000 variables using *-SEMIRING METHOD.


#include <bits/stdc++.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include<stdlib.h> 
#include <sys/types.h>
#define n 100
#define ll long long int
using namespace std;
float X[2*n][n+1];
pthread_t ptd[n];
int t,k=0,q;
void *soln(void *arg){
if(t<(q-1)){
float temp=(1/(1-X[k][k]));
for( int i=k+1;i<=n+k;i++){
for( int j=k+1;j<=n;j++){
X[i][j]+=(X[i][k] * X[k][j] * temp);}}
k++;}
else
{for(int l=k;l<=(n-1);l++){
float temp=(1/(1-X[l][l]));
for(int i=l+1;i<=n+l;i++){
for(int j=l+1;j<=n;j++){
X[i][j]+=(X[i][l] * X[l][j] * temp);}}
}
}
}

int main(){int i,j=0;
printf("no. of threads? ");
scanf("%d",&q);
clock_t tStart = clock();
ll a[n][n],b[n][1];
int k=0;
for( i=0;i<n*n;i++){
a[j][k]=rand()%40;
k++;
if(k==n){k=0;j++;}}
for(i=0;i<n;i++){
b[i][0]=rand()%40;}

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

for(t=0;t<q;t++)
pthread_create(&ptd[t],NULL,soln,&t);
for(i=0;i<q;i++)
pthread_join(ptd[i],NULL);
cout<<"\nValues of x are as follows: \n";
for(i=0;i<n;i++)
cout<<"x"<<i+1<<"= "<<X[i+n][n]<<"\n";
 printf("\nTime taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
exit(0);}
