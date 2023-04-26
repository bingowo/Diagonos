#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,m;
    long long k;
    scanf("%d %d %lld",&n,&m,&k);
    long long q[200][200]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&q[i][j]);
        }
    }
    long long res=0;
    for(int i=1;i<=n;i++)//左上
    {
        for(int j=1;j<=m;j++)
        {
            long long ans=q[i][j];
            for(int r=1;i-r>0&&j-r>0;r++)
            {
                int rr=j;
                int ll=j-r;
                for(int y=ll;y<=rr;y++)
                {
                    ans+=q[i-r][y];
                    /*printf("%lld\n",ans);*/

                }
                if(ans>=k)
                {
                    res++;
                    /*printf("1111 %d %d\n",i,j);*/
                }
            }
            ans=q[i][j];
            for(int r=1;i-r>0&&j+r<=m;r++)
            {
                int rr=j+r;
                int ll=j;
                for(int y=ll;y<=rr;y++)
                {
                    ans+=q[i-r][y];
                }
                if(ans>=k)
                {
                    res++;
                    /*printf("2222 %d %d\n",i,j);*/
                }
            }
            ans=q[i][j];
            for(int r=1;i+r<=n&&j-r>0;r++)
            {
                int ll=j-r;
                int rr=j;
                for(int y=ll;y<=rr;y++)
                {
                    ans+=q[i+r][y];
                }
                if(ans>=k)
                {
                    res++;
                    /*printf("3333 %d %d\n",i,j);*/
                }
            }
            ans=q[i][j];
            for(int r=1;i+r<=n&&j+r<=m;r++)
            {
                int ll=j;
                int rr=j+r;
                for(int y=ll;y<=rr;y++)
                {
                    ans+=q[i+r][y];
                }
                if(ans>=k)
                {
                    res++;
                    /*printf("4444 %d %d\n",i,j);*/
                }
            }
        }
    }
    printf("%lld",res);
}
