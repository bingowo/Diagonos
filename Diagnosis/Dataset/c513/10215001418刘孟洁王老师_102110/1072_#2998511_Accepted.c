#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char s[1007];
int i = 0;

void direction(long long x,long long y,int r)
{
   //printf("%lld %lld %d\n",x,y,r);
   if(r)
   {
       long long a,b;
       a = llabs(x);
       b = llabs(y);
       if(a > b)
       {
          if(x > 0)
           {
               s[i++] = 'E';
               direction(x - pow(2,r-1),y,r-1);
           }
          else
          {
              s[i++] = 'W';
               direction(x + pow(2,r-1),y,r-1);
          }
       }//需要向原点接近，也就是将x的绝对值变小；
       else if(a < b)
       {
           if(y > 0)
           {
               s[i++] = 'N';
               direction(x,y - pow(2,r-1),r-1);
            }
            else
            {
                s[i++] = 'S';
                direction(x,y + pow(2,r-1),r-1);
            }
       }//y同上；
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
            if(pow(2,r-1) <= sum&&pow(2,r) >= sum)break;//走的步数就是r；
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
