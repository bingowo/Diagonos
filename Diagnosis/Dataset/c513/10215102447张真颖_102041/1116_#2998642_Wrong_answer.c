#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int finalx,finaly;
    scanf("%ld%ld",&finalx,&finaly);
    long int x=0,y=0,step=0,sign=0;
    while(!(x==finalx&&y==finaly))
    {
        long int dx=finalx-x,dy=finaly-y;
        if(dx%2==0&&dy%2==0||dx%2&&dy%2)
        {
            printf("-1");
            sign=1;
            break;
        }
        else if(dx%2==0)
        {
            long int tx=dx/2;
            if(tx%2==0)
            {
                if(tx==0&&dy==-1) y-=1;
                else if(tx==0&&dy==1) y+=1;
                else if(((dy+1)/2)%2) y-=1;
                else y+=1;
            }
            else
            {
                if(((dy+1)/2)%2) y+=1;
                else y-=1;
            }
        }
        else
        {
            long int ty=dy/2;
            if(ty%2==0)
            {
                if(ty==0&&dx==-1) x-=1;
                else if(ty==0&&dx==1) x+=1;
                else if(((dx+1)/2)%2) x-=1;
                else x+=1;
            }
            else
            {
                if(((dx+1)/2)%2) x+=1;
                else y-=1;
            }
        }
        finalx-=(finalx-x)/2,finaly-=(finaly-y)/2;
        step+=1;
    }
    if(sign==0) printf("%ld",step);
    return 0;
}