#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp1(const void*a,const void*b)
{int*p1=(int*)a;
int*p2=(int*)b;
if(*p1>*p2) return 1;
else return -1;
}
int cmp2(const void*a,const void*b)
{int*p1=(int*)a;
int*p2=(int*)b;
if(*p1<*p2) return 1;
else return -1;
}
int main()
{int c,i;
scanf("%c",&c);
char a[100][1001];
int b[100];
for( i=0;scanf("%s",a[i])!=EOF;i++)
{b[i]=atoi(a[i]);}
if(c=='A') qsort(b,i,sizeof(b[0]),cmp1);
else qsort(b,i,sizeof(b[0]),cmp2);
printf("%d ",b[0]);
for(int k=1;k<i;k++)
{if(b[k]!=b[k-1])
    printf("%d ",b[k]);}}
