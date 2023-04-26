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
    if((x+y)%2==0)
        printf("-1");
    else
    {
        for(i=1;;i++)
        {
            if((x+y)>t)
            {
               t=t*2;
               if((x+y)<=t)
                break;
            }
        }
        printf("%d",i);
    }
    return 0;
}
