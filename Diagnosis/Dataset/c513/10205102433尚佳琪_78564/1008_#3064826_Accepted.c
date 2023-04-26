#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,y,num=0;
        scanf("%d %d",&x,&y);
        for(int i=0;i<64;i++)
        {
            if((x&1)!=(y&1))
                num++;
            x=x>>1;
            y=y>>1;
        }
        printf("%d\n",num);
    }
    return 0;
}
