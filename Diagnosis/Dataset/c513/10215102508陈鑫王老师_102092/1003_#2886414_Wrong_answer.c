#include<stdio.h>
#include<stdlib.h>
int num1(long long int n)
{
    int d=1,a=0;
    for(int t=0;t<64;t++)
    {
        if(d&n)a=a+1;
        d=d<<1;
    }
    return a;
}
int cmp(const void*a,const void* b)
{
    long long int d1,d2;
    d1=num1(*((long long int*)a));
    d2=num1(*((long long int*)b));
   if(d1!=d2)return d1>d2?-1:1;
   else return *((long long int*)a)<*((long long int*)b)?-1:1;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        getchar();
        long long int p[10000];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&p[j]);
        }
        qsort(p,N,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {

            printf("%lld%c",p[k],(k!=(N-1))?' ':'\n');
        }

    }
    return 0;


}
