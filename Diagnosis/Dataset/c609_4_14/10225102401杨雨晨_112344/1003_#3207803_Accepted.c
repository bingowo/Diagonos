#include <stdio.h>

void f(long long int m,int r)
{
if (m/r){f(m/r,r);printf(" %lld",m%r);}
else {printf("%lld",m%r);}

}
int main(){ 
int t,i,a[100],p,j;
long long int m;
scanf("%d",&t);
for(i=j=0;i<t;i++)
{
	scanf("%lld",&m);
	f(m,2333);
	printf("\n");
	
}}