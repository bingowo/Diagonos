#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct data
{
    long long int a;
    int number;
}data;

int count(long long int n)
{
    int num1=0;
    while(n!=0)
    {
        n=n&(n-1);
        num1++;
    }
    return num1;
}
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.number!=d1.number)
         return d2.number-d1.number;
    else
    {    if(d1.a>d2.a) return 1;
         else return -1;
    }
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int j=0;j<T;j++){
    struct data p[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   scanf("%lld",&p[i].a);
        p[i].number=count(p[i].a);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("case #%d:\n",j);
    for(int m=0;m<n;m++)
        printf("%lld ",p[m].a);
        printf("\n");
    }
    return 0;
}
