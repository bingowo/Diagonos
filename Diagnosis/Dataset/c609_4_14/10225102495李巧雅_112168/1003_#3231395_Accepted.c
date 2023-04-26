#include <stdio.h>
void bili(unsigned long long n)
{
    unsigned long long a[10000]={0};
    int i=0;
    while(n)
    {
        a[i]=n%2333;
        n/=2333;
        i++;
    }
    for(--i;i>0;i--)
    {
        printf("%llu ",a[i]);
    }
    printf("%llu",a[0]);
    printf("\n");
}
int main()
{
    int T;
    unsigned long long n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%llu",&n);
        bili(n);
    }
    return 0;
}
