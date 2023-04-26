#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long int lli;
typedef struct
{
    lli x;
    lli y;
}dot;
dot zero={0,0};

lli distance(dot x,dot y)
{
     return llabs(x.x-y.x)+llabs(x.y-y.y);;
}
int main()
{
    dot d;int step=0;
    scanf("%d%d",&d.x,&d.y);
    int dis =distance(zero,d);
    if (dis==0) printf("0");
    else if(dis%2==0) printf("-1");
    else
    {
        while(dis)
        {
            if(dis==1)
            {
                dis--;
                step++;
            }
            else
            {
                dis = ((dis-1)/2)%2==0?dis+1:dis-1;
                step++;
                dis/=2;
            }
        }
        printf("%d",step);
    }

}

