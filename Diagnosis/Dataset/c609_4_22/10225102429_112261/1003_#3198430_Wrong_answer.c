#include <stdio.h>
int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int a[10];
        long long n; scanf("%lld",&n);
        int i = 9;
        while(n)
        {
            a[i] = n%2333;
            n/=2333;
            i--;
        }
        i++;
        while(i<10){printf("%d%c",a[i++],i==9?'\n':' ');}

    }
    return 0;
}