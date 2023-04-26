#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long sol(long long a, long long b)
{  a=llabs(a),b=llabs(b);
    int m=0;
    while(a!=0||b!=0)
    {
        if(a%2!=0)
        {
            if(a==1&&b==0) a--;
            else if((a+1)/2%2!=b/2%2) a++;
            else a--;
            a/=2;b/=2;m++;
        }
        else
        {
            if(a==0&&b==1) b--;
            else if((b+1)/2%2!=a/2%2) b++;
            else b--;
            a/=2;b/=2;m++;
        }
    }
    return m;
}
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if((a+b)%2==0)
    {
        printf("-1");
    }
    else
    {
        printf("%lld",sol(a,b));
    }
    return 0;
}
