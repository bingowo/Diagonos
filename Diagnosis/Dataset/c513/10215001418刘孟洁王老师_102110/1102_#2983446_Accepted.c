#include <stdio.h>
#include <stdlib.h>

typedef struct{long long number,x,y;}point;

int main()
{
    long long n,a,len;
    point num;
    scanf("%lld",&n);
    num.number = n;
    for(a = 0; ; a++)
    {
        if((a+1)*(a+1) > n)break;
    }//左下角是偶数的平方，右上角为奇数的平方；
    len = n - a*a;//找到与平方数的差别；
    if(a%2)//若是奇数的平方，横坐标为a除以二的商，纵坐标为a除以二的商加一；
    {
      num.x = a/2;
      num.y = a/2+1;
      if(len > a)//当a是奇数的时候，是往左和往下移；
      {
          num.x -= a;
          num.y -= (len-a);
      }
      else num.x -= len;
    }
    else
    {
        num.x = -1*(a/2);
        num.y = -1*(a/2);//当a为偶数，横纵坐标均为a/2；且是在第三象限；
        if(len > a)
        {
            num.x += a;//a是偶数时，是向右和向上移；
            num.y += (len-a);
        }
        else num.x += len;
    }
    printf("(%lld,%lld)\n",num.x,num.y);
    return 0;
}
