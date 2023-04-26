#include<stdio.h>
#include<stdlib.h>
long long int absll(long long int a)
{
    return a<0?-a:a;
}
int first(long long int x)
{
    x=absll(x);
    int temp;
    if(x==0)temp=0;
    else
    {
    while(x)
    {
       temp=x%10;
       x/=10;
    }
    }
    return temp;
}
int cmp(const void*a,const void*b)
{
    long long int x=*(long long int*)a;
    long long int y=*(long long int*)b;
    int m=first(x),n=first(y);
    if(m!=n) return m>n?-1:1;
    else return x<y?-1:1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        long long int ret[N];
        for(int j=0;j<N;j++)
        {
            scanf("%lld",&ret[j]);
        }
        qsort(ret,N,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
            printf("%lld%c",ret[j],j==N-1?'\n':' ');
        }

    }
    return 0;
}
