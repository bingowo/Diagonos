#include<stdio.h>
#include<stdlib.h>
int ans;
int n,p,m,t;
void dsf(int x,int y)
{
    if(y<0)return;
    if(x==t&&y==0)ans++;
    else
    {
        if(x-1>0&&x-1<n+1)dsf(x-1,y-1);
        if(x+1>0&&x+1<n+1)dsf(x+1,y-1);
    }


}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        ans=0;
        dsf(p,m);
        printf("%d\n",ans);
    }
    return 0;
}
