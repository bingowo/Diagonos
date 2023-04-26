#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int ans=0;
        for(int j=0;j<32;j++)
        {
            if((x&1)!=(y&1)) ans++;
            x=x>>1;
            y=y>>1;
        }
        printf("%d\n",ans);

    }
    return 0;
}
