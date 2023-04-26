#include<stdio.h>
#define N 11
int main()
{
    int T,r,c,n,k,i,j,p,q;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int a[N][N]={0},x,y,ro,co,cnt=0,ans=0;
        for(i=0;i<n;++i)
        {
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        for(ro=1;ro<=r;++ro)
        {
            for(co=1;co<=c;++co)
            {
                for(i=1;i<=r-ro+1;++i)
                {
                    for(j=1;j<=c-co+1;++j)
                    {
                        cnt=0;
                        for(p=0;p<ro;++p)
                            for(q=0;q<co;++q)
                                if(a[i+p][j+q])cnt++;
                        if(cnt>=k)ans++;
                    }
                }   
            }
        }
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}