#include<stdio.h>
#define N 1500
#define mod 10007

long long f[1001]={0};
void init()
{
    int i;
    for (i=0;i<1001;++i)
    {
        if (!i || i==1)
        {
            f[i]=1;
        }
        else
        {
            f[i]=(f[i-1]*i)%mod;
        }
    }
}

int main()
{
    init();
    int a,b,k,n,m;
    int t;
    int i,j;

    scanf("%d",&t);

    for (i=0;i<t;++i)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);

        int an=1,bm=1;
        int res;

        for (j=0;j<n;++j)
        {
            an=(an*a)%mod;
        }

        for (j=0;j<m;++j)
        {
            bm=(bm*b)%mod;
        }

        int comb=(f[k]/(f[i]*f[k-n]));
        
        res=(comb*an*bm)%mod;
        

        printf("case #%d:\n",i);
        printf("%d\n",res);

    }
    return 0;
}

