#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//typedef struct SSS
//{
//    double p;
//    double an;
//}sss;
int cmp1(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *a-*b;
}
int cmp2(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return *b-*a;
}
int main()
{
    char ch;
    scanf("%c",&ch);
    int a[110];
    int i=0;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        a[i]=x;
        i++;
    }
    if(ch=='A') qsort(a,i,sizeof(a[0]),cmp1);
    else qsort(a,i,sizeof(a[0]),cmp2);
    int b[110];
    int k=0;
    for(int j=0;j<i-1;j++)
    {
        if(a[j]!=a[j+1]) b[k++]=a[j];
    }
    b[k++]=a[i-1];
    for(int j=0;j<k-1;j++)
    {
        printf("%d ",b[j]);
    }
    printf("%d\n",b[k-1]);
    return 0;
}
