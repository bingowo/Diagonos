#include <stdio.h>
#include <stdlib.h>


long long int num[41][41];

int main()
{
    long long solve(int m,int n);
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        long long m,n;
        scanf("%lld %lld",&m,&n);

        if(m<2*n) n=m-n;
        long long ans;
        if(n==0) ans=1;
        else if(n==1) ans=m;
        else{
            int mu[45];
            int nu[45];
            for(int j=m-n+1;j<=m;j++)
                mu[j]=j;
            for(int j=1;j<=n;j++)
                nu[j]=j;

            for(int j=m;j>=m-n+1;j--)
            for(int i=n;i>=1;i--)
            {
                if(mu[j]==2*nu[i])
                {
                    mu[j]=2;
                    nu[i]=1;
                    break;
                }
            }
            for(int j=m;j<=m-n+1;j--)
                for(int i=n;i>=1;i--)
                {
                    if(mu[j]==2) break;
                    else if(nu[i]==1) continue;
                    else if(mu[j]!=2&&nu[i]!=1)
                    {
                        if(mu[j]%nu[i]==0)
                        {
                            mu[j]=mu[j]/nu[i];
                            nu[i]=1;
                        }
                    }
                }
            printf("%d",mu[39]);
            long long high=1;
            long long low=1;

            for(int i=m-n+1;i<=m;i++)
                high*=mu[i];
            for(int i=1;i<=n;i++)
                low*=nu[i];

            ans=high/low;

        }

        printf("case #%d:\n",z);
        printf("%lld",ans);
        printf("\n");

    }
    return 0;
}


