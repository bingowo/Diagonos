#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[31],b[31];
void acculate(int n,int m,int t,int*c)
{if(t==n)
{for(int i=0;i<m;i++) {a[i]='1';}
if(strstr(b,a)) c[0]++;
return;}
else{for(int k=0;k<2;k++)
{b[t]=k+'0';
acculate(n,m,t+1,c);}}}
int main()
{int n,m;
while(scanf("%d%d",&n,&m)&&(n!=-1||m!=-1))
{int c[1]={0};
acculate(n,m,0,c);
printf("%d\n",c[0]);
}}