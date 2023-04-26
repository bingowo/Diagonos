#include <stdio.h>
#include <stdlib.h>

int f(int x,int y)
{
    int ans=0,m,n;
    if(x>y){m=x;n=y;}
    else{m=y;n=x;}
    while(m)
    {
        if((m&1)^(n&1))ans+=1;
        m=m>>1;
        n=n>>1;
    }
    return ans;
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}
