#include <stdio.h>
#include <stdlib.h>



char path[1000000]={0};
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    if(x%2==0&&y%2==0||x%2!=0&&y%2!=0)
        printf("-1");
    else
    {
        long long step=0,x0=0,y0=0;
        while(!(x0==x&&y0==y))
        {
            if((x-x0)%2==0)
            {
                long long tx=(x-x0)/2;
                if(tx%2==0)
                {
                    if(tx==0&&y-y0==-1) y0-=1,path[step]='S';
                    else if(tx==0&&y-y0==1) y0+=1,path[step]='N';
                    else if(((y-y0+1)/2)%2!=0) y0-=1,path[step]='S';
                    else y0+=1,path[step]='N';
                }
                else
                {
                    if(((y-y0+1)/2)%2==0) y0-=1,path[step]='S';
                    else y0+=1,path[step]='N';
                }
            }
            else
            {
                long long ty=(y-y0)/2;
                if(ty%2==0)
                {
                    if(ty==0&&x-x0==-1) x0-=1,path[step]='W';
                    else if(ty==0&&x-x0==1) x0+=1,path[step]='E';
                    else if((x-x0+1)/2%2!=0) x0-=1,path[step]='W';
                    else x0+=1,path[step]='E';
                }
                else
                {
                    if((x-x0+1)/2%2==0) x0-=1,path[step]='W';
                    else x0+=1,path[step]='E';
                }
            }
            x=x-(x-x0)/2,y=y-(y-y0)/2;
            step++;
        }
        printf("%lld\n%s",step,path);
    }
    return 0;
}