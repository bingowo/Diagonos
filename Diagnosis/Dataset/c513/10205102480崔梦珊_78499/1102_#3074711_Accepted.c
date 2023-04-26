#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef long long  ll;

ll lsqrt(ll x) {
        // 注意：特殊用例判断
        if (x == 0) {
            return 0;
        }
        if (x < 4) {
            return 1;
        }

        int left = 0;
        int right = x / 2;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (mid > x / mid) {
                // 下一轮搜索的区间是 [left..mid - 1]
                right = mid - 1;
            } else {
                // 下一轮搜索的区间是 [mid..right]
                left = mid;
            }
        }
        return left;
    }

int main()
{
    ll n;
    scanf("%lld",&n);
    ll flag=0;
    flag=(ll)sqrt(n);
    if(flag*flag>n) flag--;
    //printf("%lld\n",flag);
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
