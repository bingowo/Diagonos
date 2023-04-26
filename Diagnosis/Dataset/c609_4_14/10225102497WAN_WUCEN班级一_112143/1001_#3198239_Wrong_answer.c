#include<stdlib.h>
#include<stdio.h>
main()
{char out[33];
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a,b,c,d;
int i=0;
scanf("%d%d",&a,&b);
do out[i++]=table[a%b];
while (a=a/b);
for(i=0;out[i+1]!='\0';i++);
for(;i>=0;i--)
printf("%c",out[i]);}
