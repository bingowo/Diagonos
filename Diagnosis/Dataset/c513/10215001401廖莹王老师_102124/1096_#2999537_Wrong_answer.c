#include <stdio.h>
#include <stdlib.h>

void jisuan(int h)
{
    int in[105],out[105],a[105][105]={0};
    memset(in,0,sizeof in);memset(out,0,sizeof out);memset(a,0,sizeof a);
    int n,i=0,s=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==y || a[x][y]!=0)continue;
        a[x][y]=1;
        if(out[y]!=0 || in[x]!=0 || out[x]!=0  )s=0;
        in[x]=1;out[y]=1;
    }
    if(s!=0)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
        return;
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
