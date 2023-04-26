#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char s[1007];
int i = 0;

void direction(long long x,long long y,int r)
{
    if(x == 0&&y == 0)return ;
    //printf("%lld %lld\n",x,y);
   else
   {
        long long a,b,x1,x2,y1,y2,sum1,sum2;
        a = llabs(x);
        b = llabs(y);
       if(a > b)
       {
           x1 = x - pow(2,r-1);
           x2 = x + pow(2,r-1);
           sum1 = llabs(x1) + b;
           sum2 = llabs(x2) + b;
           if(pow(2,r-2) <= sum1&&pow(2,r-1) >= sum1)
           {
               s[i++] = 'E';
               return direction(x1,y,r-1);
           }
           else if(pow(2,r-2) <= sum2&&pow(2,r-1) >= sum2)
           {
               s[i++] = 'W';
               return direction(x1,y,r-1);
           }
       }
       else if(a < b)
       {
           y1 = y - pow(2,r-1);
           y2 = y + pow(2,r-1);
           sum1 = llabs(y1) + a;
           sum2 = llabs(y2) + a;
           if(pow(2,r-2) <= sum1&&pow(2,r-1) >= sum1)
           {
               s[i++] = 'N';
               return direction(x,y1,r-1);
           }
           else if(pow(2,r-2) <= sum2&&pow(2,r-1) >= sum2)
           {
               s[i++] = 'S';
               return direction(x,y2,r-1);
           }
       }
   }
}
int main()
{
    long long x,y,r,sum;
    int j;
    scanf("%lld%lld",&x,&y);
    sum = llabs(x)+llabs(y);
    if(x == 0&& y == 0)printf("0");
    else if(sum%2 == 0)printf("-1");
    else
    {
        for(r = 1; r < 42; r++)
        {
            if(pow(2,r-1) <= sum&&pow(2,r) >= sum)break;
        }
        //r = (log10(sum))/(log10(2))+1;
        printf("%lld\n",r);
        direction(x,y,r);
        s[i] = '\0';
        for(j = 0; j <= (i-1)/2; j++)
        {
            char p = s[j];
            s[j] = s[i-1-j];
            s[i-1-j] = p;
        }
        printf("%s\n",s);
        //printf("%d",i);
    }
    return 0;
}
