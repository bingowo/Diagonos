#include <stdio.h>

void f(int m,int r)
{int j=0;
if (m/r){f(m/r,r);printf(" %d",m%r);}
else {printf("%d",m%r);}

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