#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef unsigned long long ll;

int main()
{
    ll n;
    scanf("%llu",&n);
    ll flag=0;
    for(ll i=0;i<=n;i++)
    {
        if(n>=i*i&&n<(i+1)*(i+1))
        {
            flag=i;
            break;
        }
    }
    //printf("%lld %lld\n",flag,flag*flag%2);
    ll x,y;
    ll te=n-flag*flag;
    if(flag%2==0)
    {
        ll temp=flag*flag;//36
        x=0-(flag/2);//-3
        y=0-(flag/2);//-3
        //printf("%lld %lld %lld\n",temp,x,y);
        if(te<=flag)
        {
            x+=te;//16 17 18 19 20
        }
        else//42
        {
            x=flag/2;//3
            y+=te-flag;
        }
    }
    else
    {
        ll temp=flag*flag;
        x=(flag/2);
        y=(flag/2)+1;
        //printf("%lld %lld %lld\n",temp,x,y);
        if(te<=flag)
        {
            x-=te;
        }
        else
        {
            x=-1-flag/2;
            y-=te-flag;
        }
    }
    printf("(%llu,%llu)\n",x,y);
    return 0;
}
