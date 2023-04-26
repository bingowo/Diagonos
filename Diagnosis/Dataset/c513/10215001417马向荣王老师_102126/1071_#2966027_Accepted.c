#include<stdio.h>
int main()
{
        int t,p;
        scanf("%d\n",&t);
        int mod=10007;
        for(p=0;p<t;p++)
        {
                int a,b,k,n,m;
                scanf("%d %d %d %d %d\n",&a,&b,&k,&n,&m);
                long long int d[1001][1001]={0};
                int i,j;
                d[0][0]=1;
                for(i=1;i<1001;i++)
                {
                        d[i][0]=1,d[i][1]=(i%mod);
                }
                for(i=1,j=1;i<1001,j<1001;i++,j++)
                {
                        if(i==j) d[i][j]=1;
                }
                for(i=2;i<1001;i++)
                {
                        for(j=1;j<=i;j++)
                        {
                                if(i>=j) d[i][j]=(d[i-1][j-1]+d[i-1][j])%mod;
                        }
                }
                long long int s=d[k][n],c=1,e=1;
                for(i=0;i<n;i++)
                {
                        c=(c*a)%mod;
                }
                for(i=0;i<m;i++)
                {
                        e=(e*b)%mod;
                }
                printf("case #%d:\n",p);
                printf("%d\n",(((((s%mod)*e)%mod)*c)%mod));
        }
}