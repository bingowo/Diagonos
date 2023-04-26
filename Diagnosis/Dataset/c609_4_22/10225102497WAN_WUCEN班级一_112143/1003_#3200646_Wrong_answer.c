#include<stdio.h>
#define POWER 2333
main()
{int out[600][10];
int count[600];
int a,c,d,T;
int i=0;
scanf("%d",&T);
for(c=0;c<T;c++)
{scanf("%d",&a);
do {out[c][i++]=a%POWER;count[c]++;}
while (a=a/POWER);
i=0;}
for(c=0;c<T;c++)
{for(i=0;i<count[c]-1;i++);
for(;i>=0;i--)
printf("%d ",out[c][i]);
printf("\n");}
}
