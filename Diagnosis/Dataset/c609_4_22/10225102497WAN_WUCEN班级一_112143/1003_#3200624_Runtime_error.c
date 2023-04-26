#include<stdlib.h>
#include<stdio.h>
main()
{int out[50][3];
int count[50];
int a,c,d,T;
int i=0;
scanf("%d",&T);
for(c=0;c<T;c++)
{scanf("%d",&a);
do {out[c][i++]=a%2333;count[c]++;}
while (a=a/2333);
i=0;}
for(c=0;c<T;c++)
{for(i=0;i<count[c]-1;i++);
for(;i>=0;i--)
printf("%d ",out[c][i]);
printf("\n");}
}
