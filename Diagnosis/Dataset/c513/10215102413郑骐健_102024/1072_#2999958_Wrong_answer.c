#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long res = labs(x) + labs(y);
    long long x1 = labs(x),y1 = labs(y);
    if(res%2==0)printf("-1");
    else
    {
        int res2[200];
        int cnt=0;
        do
        {
            res2[cnt++] = res%2;
            res/=2;
        }while(res!=0);
        for(int i =0;i<cnt;i++)
        {
            if(!res2[i])
            {
                res2[i-1]=-1;
                res2[i]=1;
            }
        }
        int x2[200],px=0;
        int y2[200],py=0;
        memset(x2,0,sizeof(x2));
        memset(y2,0,sizeof(y2));
        long long base = 2;
        int q=0;
        while(x1!=0)
        {
            if(x1%base)
            {
                x2[q] = res2[q];
                x1 -= base*res2[q]/2;
            }
            base*=2;
            q++;
        }
        base = 2;
          int q2=0;
          while(y1!=0)
        {
            if(y1%base)
            {
                y2[q2] = res2[q2];
                y1 -= base*res2[q2]/2;
            }
            base*=2;
            q2++;
        }


        char mx[4];
        char my[4];
        if(x>0)
            {
                mx[3]='E';
                mx[1] = 'W';
            }
        else
        {
              mx[1]='E';
                mx[3] = 'W';
        }
        if(y>0)
        {
            my[3] = 'N';
            my[1] = 'S';
        }
        else
        {
            my[3] = 'S';
            my[1] = 'N';
        }
        char s[200];
        for(int i =0;i<cnt;i++)
        {
            if(x2[i])
            {
                s[i] = mx[x2[i]+2];
            }
            if(y2[i])
            {
                s[i] = my[y2[i]+2];
            }
        }
        for(int x=0;x<cnt;x++)
        {
            printf("%c",s[x]);
        }
    }
    return 0;
}
