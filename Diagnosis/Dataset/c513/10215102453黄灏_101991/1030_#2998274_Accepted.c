#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<ctype.h>

int jdg(long long x)
{
    int t=0;
    long long num=x;
    if(num<0) num=-num;
    while(num!=0)
    {
        t=num%10;
        num/=10;
    }
    return t;
}

int cmp(const void *a,const void *b)
{
    long long *p1=(long long*)a,*p2=(long long*)b;
    int s1=jdg(*p1),s2=jdg(*p2);
    if(s1==s2)
    {
        if(*p1>*p2) return 1;
        else return -1;
    }
    else return s2-s1;
}

int main()
{
    int i,j,N,T;
    long long a[10001];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
        {
            scanf("%lld",&a[j]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n%lld",i,a[0]);
        for(j=1;j<N;j++)
            printf(" %lld",a[j]);
        printf("\n");
    }
    return 0;
}
