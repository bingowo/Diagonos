#include <stdio.h>

int
main()
{
    int T;
    int n;
    int x,y;
    int flag = 1;
    
    scanf("%d",&T);
    for (int i=0; i<T; i++)
    {
        flag = 1;
        int in[101]={0},out[101]={0},order[101][101];
        
        scanf("%d",&n);
        for (int j=0; j<n; j++)
        {
            scanf("%d%d",&x,&y);
            if (x==y || order[x][y])
            {
                continue;
            }
            order[x][y] = 1;
            if (out[y] || in[x] || out[x])
            {
                flag = 0;
                break;
            }
            out[x] = 1;
            in[y] = 1;
        }
        
        if (flag)
        {
            printf("Lucky dxw!\n");
        }
        else
        {
            printf("Poor dxw!\n");
        }
    }
    
    return 0;
}