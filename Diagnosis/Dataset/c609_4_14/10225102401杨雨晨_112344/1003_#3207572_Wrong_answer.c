#include <stdio.h>
int f(int m,int r,int s[])
{int j=0;
if (m/r){f(m/r,r,s);}
s[j++]=m%r;
return j-1;
}
int main(){ 
int t,i,a[100],p,m,j;
scanf("%d",&t);
for(i=0;i<t;i++)
{
	scanf("%d",&m);
	j=f(m,2333,a);
	for (p=0;p<j;p++) 
	{printf("%d ",a[p]);}
	
}}