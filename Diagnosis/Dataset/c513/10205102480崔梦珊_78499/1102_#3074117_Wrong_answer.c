#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef long long ll;

int main()
{
    ll n;
    scanf("%lld",&n);
    ll flag=0;
    for(ll i=0;i<=n;i++)
    {
        if(n>=i*i&&n<(i+1)*(i+1))
        {
            flag=i;
            break;
        }
    }
    /*printf("%llu %llu\n",flag,flag*flag%2);*/
    ll x,y;
    ll guai=(flag*flag)+(flag+1)*(flag+1);
    guai=guai/2;
    if((flag*flag)%2==0)
    {
        ll temp=flag*flag;
        x=0-(flag/2);
        y=0-(flag/2);
        /*printf("%lld %lld %lld\n",temp,x,y);*/
        if(n<=guai)
        {
            while(temp!=n)
            {
                x++;
                temp++;
            }
        }
        if(n>guai)
        {
            x=flag/2;
            while(temp!=n)
            {
                y++;
                temp++;
            }
        }
    }
    else
    {
        ll temp=flag*flag;
        x=(flag/2);
        y=(flag/2)+1;
        /*printf("%lld %lld %lld\n",temp,x,y);*/
        if(n<=guai)
        {
            while(temp!=n)
            {
                x--;
                temp++;
            }
        }
        if(n>guai)
        {
            x=-1-flag/2;
            temp=guai;
            while(temp!=n)
            {
                y--;
                temp++;
            }
        }
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}
