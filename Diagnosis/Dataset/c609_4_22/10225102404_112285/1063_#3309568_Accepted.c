#include<stdio.h>

#define N 50

long long f(int n)
{
    static long long m[N];
    if(n<0)
    {
        return 0;
    }
    if(!m[n])
    {
        m[n]=n?f(n-1)+f(n-2)+f(n-3)+f(n-4):1;
    }
    return m[n];

}

int main()
{
    int I,T,n;
    for(scanf("%d",&T),I=0;I<T;I++)
    {
        printf("case #%d:\n""%lld\n",I,f((scanf("%d",&n),n)));
    }
    return 0;
}
