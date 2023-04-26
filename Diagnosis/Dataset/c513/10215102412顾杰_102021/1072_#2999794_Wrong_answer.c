#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"

char ans[100]={};
void path(long long x, long long y,int step)
{
    if(x||y)
    {
        long long x0=llabs(x),y0=llabs(y);
        long long t=1LL<<step;
        if(x0>y0)if(x>0){x-=t;ans[step]='E';}
                 else {x+=t;ans[step]='W';}
        else if(y>0){y-=t;ans[step]='N';}
              else {y+=t;ans[step]='S';}
        step--;
        //printf("%d %d\n",x,y);
        path(x,y,step);
    }
}

int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    long long x0=llabs(x),y0=llabs(y);
    int step=(int)(log(x0+y0)/log(2));
    if(x0==0&&y0==0)printf("0");
    else if((x0+y0)%2==0)printf("-1");
    else {printf("%d\n",step+1);path(x,y,step);for(int i=0;i<=10;i++)printf("%c",ans[i]);}//for(int i=strlen(ans)-1;i>=0;i--)printf("%c",ans[i]);}
}
