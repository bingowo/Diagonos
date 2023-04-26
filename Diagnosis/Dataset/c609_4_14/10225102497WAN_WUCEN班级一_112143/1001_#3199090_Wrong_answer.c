#include<stdlib.h>
#include<stdio.h>
main()
{char out[50][35];
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a,b,c,d,T,sign=0;
int i=0;
scanf("%d",&T);
for(c=0;c<T;c++)
{scanf("%d%d",&a,&b);
if (a<0){sign=-1;a=-a;}
do {out[c][i++]=table[a%b];}
while (a=a/b);
if (sign==-1)out[c][i++]='-';
out[c][i++]=0;
i=0;}
for(c=0;c<T;c++)
{for(i=0;out[c][i]!='\0';i++);
i--;
for(;i>=0;i--)
printf("%c",out[c][i]);
printf("\n");}
}
