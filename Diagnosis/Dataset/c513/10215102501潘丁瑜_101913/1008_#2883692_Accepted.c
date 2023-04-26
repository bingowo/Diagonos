#include <stdio.h>
#include <stdlib.h>
int estimate(x);
int main()
{
    int T,i,x,y;
    int a,b;
    int bit = 0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&x,&y);
        bit = 0;
        while(x>0 || y>0)
        {
            if(estimate(x) != estimate(y))
                bit++;
            x=x>>1;
            y=y>>1;
        }
        printf("%d\n",bit);
    }
    return 0;
}
int estimate(x)
{
    int res;
    if(x&1 == 1) res = 1;
    else res = 0;
    return res;
}
