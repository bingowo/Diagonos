#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long int x,y,x1,y1,t=1;
    int i;
    scanf("%d %d",&x1,&y1);
    x=abs(x1);
    y=abs(y1);
    if(x==0&&y==0)
        printf("0");
    else if((x+y)%2==0)
        printf("-1");
    else
    {
        for(i=1;;i++)
        {
            if((x+y+1)>t)
            {
               t=t*2;
               if((x+y+1)<=t)
                break;
            }
        }
        printf("%d",i);
    }
    return 0;
}
