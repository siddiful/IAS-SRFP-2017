// Author: Siddharth Shukla
// Recursive solution (sequential) of finding the solutions of linear algebraic equations (of form AX=B) having upto 1000 variables using SUCCESSIVE GAUSS ELIMINATION.


#include<bits/stdc++.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include<stdlib.h> 
#include <sys/types.h>
#define ll long long int
#define pb push_back

using namespace std;
vector<float> ans;
void fwdelim(vector<vector<float> > &c,int n,int m){
int q,i,j,k;
for(k=0;k<(n/2);k++){
float max=c[k][k];
for(i=k;i<n;i++)
if(c[i][k]>=max){max=c[i][k];q=i;}
for(i=0;i<m;i++)
{float g=c[q][i];c[q][i]=c[k][i];c[k][i]=g;}
for(q=k+1;q<n;q++)
c[q][k]=(c[q][k]/c[k][k]);
for(j=k+1;j<m;j++)
for(i=k+1;i<n;i++)
c[i][j]-=((c[i][k])*(c[k][j]));
}
}

void bwdelim(vector<vector<float> > &b,int n,int m){
int q,i,j,k;
for(k=m-2;k>=(n/2);k--){
float max=b[k][k];
for(i=k;i>=0;i--)
if(b[i][k]>=max){max=b[i][k];q=i;}
for(i=0;i<m;i++)
{float g=b[q][i];b[q][i]=b[k][i];b[k][i]=g;}
for(q=k-1;q>=0;q--)
b[q][k]=(b[q][k]/b[k][k]);
for(j=k-1;j>=0;j--)
for(i=k-1;i>=0;i--)
b[i][j]-=((b[i][k])*(b[k][j]));

for(i=k-1;i>=0;i--)
b[i][m-1]-=((b[i][k])*(b[k][m-1]));
}
}

void SGE(vector<vector<float> > &a,int n,int m){
if(n>1){
vector<vector<float> >a1,a2;
for(int i=0;i<n;i++){vector<float> v;
for(int j=0;j<m;j++){
v.pb(a[i][j]);}
a1.pb(v);a2.pb(v);}
fwdelim(a1,n,m);
bwdelim(a2,n,m);
vector<vector<float> >a3,a4;

for(int i=0;i<n/2;i++){vector<float> v;
for(int j=0;j<n/2;j++)
{v.pb(a2[i][j]);}v.pb(a2[i][m-1]);
a4.pb(v);}

for(int i=n/2;i<n;i++){vector<float> v;
for(int j=n/2;j<n;j++){
v.pb(a1[i][j]);}v.pb(a1[i][m-1]);
a3.pb(v);}

SGE(a3,n/2,n/2+1);
SGE(a4,n/2,n/2+1);
}
else ans.pb(a[0][1]/a[0][0]);
}

int main(){
clock_t tStart = clock();
float q;
int i,j,r=1000,c=1001;
vector<vector<float> >a;
//printf("Enter no. of rows: ");scanf("%d",&500);
//printf("Enter no. of columns: ");scanf("%d",&501);
for(i=0;i<r;i++){
vector<float> v;
for(j=0;j<c;j++){
//scanf("%f",&q);
v.pb(rand()%25);
}
a.pb(v);
}
SGE(a,r,c);
for(i=0;i<ans.size();i++)
{printf("x[%d] = %f\n",i+1,ans[i]);}
printf("\nTime taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
exit(0);} 
