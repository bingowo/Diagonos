#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int N=105;
bool in[N],out[N],a[N][N];
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
        bool ans=true;
        for(int k=0;k<n;k++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(x==y||a[x][y]) continue;
            a[x][y]=true;
            if(out[y]||in[x]||out[x]||)
                ans=false;
            out[x]=in[y]=true;
        }
        puts(ans?"Lucky dxw!":"Poor dxw!");
    }
    return 0;
}
