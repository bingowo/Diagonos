#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int n,i,t,l,j,m;
char k;
char answer[10000];
char p[35]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
scanf("%d",n);
for(i=0;i<n;i++)
{long long int s,m;
scanf("%lld",s);
scanf("%d",m);
if(s<0){printf("-");s=-s;}
for(t=0;s;t++)
{answer[t]=s%m;
s=s/m;}
for(t--;t>0;t--)
{printf("%c",p[answer[t]]);}
printf("%c\n",p[answer[0]]);
}}
