#include <stdio.h>
int j=0;
int f(int m,int r,int s[])
{
if (m/r){f(m/r,r,s);}
s[j++]=m%r;
}
int main(){ 
int t,i,a[100],p,m;
scanf("%d",&t);
for(i=0;i<t;i++)
{
	scanf("%d",&m);
	f(m,2333,a);
	for (p=0;p<j;p++) 
	{printf("%d ",a[p]);}
	
}}