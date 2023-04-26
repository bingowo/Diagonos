#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long int a;
    scanf("%lld",&a);
    long long int b = 0;
    while((b+1) * (b+1) <= a)//b² <= a < (b+1)²
        b++;
    /*这种循环不会很大 肯定是够用的循环 小于2000
    10000次for循环大概用的是0.08s
    只要不出现循环嵌套指数级增长都没有问题（例如之前的杨辉三角数组储存问题）
    */
    long long int c = a - b * b;
    int side;//side表示是在右下角还是左上角
    side=b%2;//side=1是在左上角先往左再往下
    long long int x,y;
    if(side==1)//side=1是从右上角的点开始往左
    {
        y=b/2+1;
        x=y-1;
        long long int temp=((b+1)*(b+1)-b*b+1)/2;
        int tt=0;
        if(c<=temp-1)
        {
            x-=c;
        }
        else if(c>temp-1)
        {
            x=x-temp+1;
            y=y-(c-temp+1);
        }
    }
    else if(side==0)
    {
        y=-b/2;
        x=y;
        long long int temp=((b+1)*(b+1)-b*b+1)/2;
        int tt=0;
        /*while(c!=0)
        {
            if(tt<temp-1)
            {
                x++;
                tt++;
                c--;
            }
            else if(tt>=temp-1)
            {
                y++;
                tt++;
                c--;
            }
        }*/
        if(c<=temp-1)
        {
            x+=c;
        }
        else if(c>temp-1)
        {
            x=x+temp-1;
            y=y+(c-temp+1);
        }
    }

    printf("(%lld,%lld)",x,y);
}
