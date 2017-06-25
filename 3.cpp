// Author: Siddharth Shukla
// Non-recursive solution (sequential) of finding the solutions of linear algebraic equations (of form AX=B) having upto 1000 variables using SUCCESSIVE GAUSS ELIMINATION.

#include<bits/stdc++.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include<stdlib.h> 
#include <sys/types.h>
#define ll long long int
#define pb push_back
using namespace std;
int main(){
clock_t tStart = clock();
ll i,j,k,q,r=200,c=201;
vector<vector<float> >A,B,C;
for(i=0;i<r;i++){
vector<float> v;
for(j=0;j<c;j++){
v.pb(rand()%25);
}
A.pb(v);
}
ll l=0,n=r,m=n,t;

while(m>1){
t=0;//for(i=0;i<n;i++){B[i].clear();C[i].clear();}
for(i=0;i<r;i++){
vector<float> v;
for(j=0;j<c;j++){
v.pb(A[i][j]);}B.pb(v);C.pb(v);}

for(t=0;t<(n/m);t++){//seeeeeeeeee
for(k=0+t*m;k<((m/2)+t*m);k++){
float max=B[k][k];
for(i=k;i<m+t*m;i++)
if(B[i][k]>=max){max=B[i][k];q=i;}
for(i=0+t*m;i<m+t*m;i++)
{float g=B[q][i];B[q][i]=B[k][i];B[k][i]=g;}
for(q=k+1;q<m+t*m;q++)
B[q][k]=(B[q][k]/B[k][k]);
for(j=k+1;j<m+t*m;j++)
for(i=k+1;i<m+t*m;i++)
B[i][j]-=((B[i][k])*(B[k][j]));
for(i=k+1;i<m+t*m;i++)
B[i][c-1]-=((B[i][k])*(B[k][c-1]));
}//for k

for(i=0+t*m;i<((m/2)+t*m);i++)
for(j=0+t*m;j<((m/2)+t*m);j++)
A[i][j]=B[i][j];
for(i=0+t*m;i<((m/2)+t*m);i++)
A[i][c-1]=B[i][c-1];
}//for t		

for(t=0;t<(n/m);t++){
for(k=c-2-t*m;k>=(c-2)-(m/2)-t*m+1;k--){
float max=C[k][k];
for(i=k;i>=t*m;i--)
if(C[i][k]>=max){max=C[i][k];q=i;}
for(i=(c-2)-t*m;i>=(c-2)-(t)*m-m+1;i--)
{float g=C[q+1][i];C[q+1][i]=C[k][i];C[k][i]=g;}
for(q=k-1;q>=(r-1)-t*m-m+1;q--)
C[q][k]=(C[q][k]/C[k][k]);
for(j=k-1;j>=(c-2)-(t)*m-m+1;j--)
for(i=k-1;i>=(r-1)-t*m-m+1;i--)
C[i][j]-=((C[i][k])*(C[k][j]));
for(i=k-1;i>=(r-1)-t*m-m+1;i--)
C[i][c-1]-=((C[i][k])*(C[k][c-1]));
}
for(i=c-2-t*m;i>=(c-2)-(m/2)-t*m+1;i--)
for(j=c-2-t*m;j>=(c-2)-(m/2)-t*m+1;j--)
A[i][j]=C[i][j];
for(i=c-2-t*m;i>=(c-2)-(m/2)-t*m+1;i--)
A[i][j]=C[i][j];
}
m/=2;
}

printf("Values of X:\n");
for(i=0;i<n;i++)
printf("%.6f ",(A[i][c-1]/A[i][i]));
printf("\n");
printf("\nTime taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
exit(0);} 
