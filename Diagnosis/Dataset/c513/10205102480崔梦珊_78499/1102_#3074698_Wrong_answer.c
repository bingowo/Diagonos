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
    flag=(int)sqrt(n);
    //printf("%lld %lld\n",flag,flag*flag%2);
    ll x,y;
    ll te=n-flag*flag;
    if(flag%2==0)
    {//36
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
    printf("(%lld,%lld)\n",x,y);
    return 0;
}
