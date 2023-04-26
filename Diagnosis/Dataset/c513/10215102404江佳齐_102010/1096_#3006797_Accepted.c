#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int in[105],out[105],a[105][105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        int n;
        scanf("%d",&n);
        int ans=1;
        for(int k=0;k<n;k++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(x==y||a[x][y]) continue;
            a[x][y]=1;
            if(out[y]||in[x]||out[x])
                ans=0;
            out[x]=in[y]=1;
        }
        puts(ans?"Lucky dxw!":"Poor dxw!");
    }
    return 0;
}
