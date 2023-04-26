#include <stdio.h>
#include <stdlib.h>

long long int Tribonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1||n==2)
        return 1;
    return (Tribonacci(n-1)+Tribonacci(n-2)+Tribonacci(n-3));
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int n;
        long long int m;
        scanf("%d",&n);
        m=Tribonacci(n);
        printf("case #%d:\n%lld\n",i,m);
    }
}