#include <stdio.h>

void f(int m,int r)
{int j=0;
if (m/r){f(m/r,r);printf(" %d",m%r);}
else {printf("%d",m%r);}

}
int main(){ 
int t,i,a[100],p,m,j;
scanf("%d",&t);
for(i=j=0;i<t;i++)
{
	scanf("%d",&m);
	f(m,2333);
	printf("\n");
	
}}