#include<stdio.h>
unsigned long long find(unsigned long long n)
{
    unsigned long long a=n+1;
    if(a%9==0)
    {
        return find(a);
    }
    else
    {
        int t=0;
        unsigned long long b=a;
        while(b>0)
        {
            if(b%10==9)
            {
                t++;
            }
            b=b/10;
        }
        if(t==0)
        {
            return a;
        }
        else
        {
            return find(a);
        }
    }
}
int main()
{
    unsigned long long n;
    scanf("%llu",&n);
    printf("%llu",find(n));
    return 0;
}