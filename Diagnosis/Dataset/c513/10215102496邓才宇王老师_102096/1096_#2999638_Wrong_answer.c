#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int p1[200],p2[200];
        int ans[200][200];
        memset(p1,0,sizeof(p1));
        memset(p2,0,sizeof(p2));
        memset(ans,0,sizeof(ans));
        int flag=1;
        for(int j=0;j<n;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            p1[a]=1;p2[b]=1;
        }
        for(int q=1;q<=100;q++)
        {
            for(int w=1;w<=100;w++)
            {
                if(p1[q]==1&&p2[w]==1)
                    ans[q][w]=1;
            }
        }
        for(int q=1;q<=100;q++)
        {
            for(int w=1;w<=100;w++)
            {
                if(q==w) continue;
                else
                {
                    if(ans[q][w]==1&&(p2[q]==1||p1[w]==1)) flag=0;
                    else
                    {
                        for(int r=1;r<=100;r++)
                        {
                            if(ans[q][w]==1&&p2[r]==1&&r!=w) flag=0;
                        }
                    }
                }
            }
        }
        if(flag==0) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
