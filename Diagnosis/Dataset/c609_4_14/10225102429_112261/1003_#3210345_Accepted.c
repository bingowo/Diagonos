#include <stdio.h>
int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int a[100];
        long long n; scanf("%lld",&n);
        if(n==0){printf("0\n"); continue;}
        int i = 99;
        while(n)
        {
            a[i] = n%2333;
            n/=2333;
            i--;
        }
        i++;
        while(i<100){printf("%d%c",a[i++],i==99?'\n':' ');}
    }
    return 0;
}