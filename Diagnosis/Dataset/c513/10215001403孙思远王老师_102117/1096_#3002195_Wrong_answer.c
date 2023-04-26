#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct ww
    {
        int x;
        int y;
    };
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int n,i,flag=0;
        scanf("%d",&n);
        struct ww w[n];
        for(i=0;i<n;i++)
            scanf("%d%d",&w[i].x,&w[i].y);
        for(i=0;i<n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(w[i].x==w[j].y)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("Poor dxw!\n");
        else
            printf("Lucky dxw!\n");
    }
    return 0;
}
