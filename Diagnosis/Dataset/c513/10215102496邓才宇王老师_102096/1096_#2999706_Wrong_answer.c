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
            if(a==b||ans[a][b]) continue;
            if(p1[b]||p2[a]||p1[a]) flag=0;
            p1[a]=p2[b]=1;
        }
        if(flag==0) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
