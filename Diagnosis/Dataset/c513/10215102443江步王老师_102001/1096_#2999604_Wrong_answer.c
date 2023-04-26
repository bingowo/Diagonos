#include<stdio.h>
#include<stdlib.h>
#define N 101

int begin[N]={0};
int end[N]={0};
int a[N][N]={0};

int main()
{
    int t;
    scanf("%d",&t);

    for (int i=0;i<t;++i)
    {
        int n;
        int x,y;
        int ans=1;
        scanf("%d",&n);

        memset(begin,0,N);//初始化数组begin和end
        memset(end,0,N);
        memset(a,0,N*N);

        for (int j=0;j<n;++j)
        {
            scanf("%d %d",&x,&y);

            if (x == y || a[x][y])
            {
                continue;   
            }
            
            if (!a[x][y]) 
            {
                a[x][y]=1;
                begin[x]=1;end[y]=1;
            }

            if (end[x] || begin[y] || begin[x])
            {
                ans=0;break;
            }
            
        }
        if (ans)
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