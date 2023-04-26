#include<stdio.h>

int main()
{
    int a,b,k,n,m;
    int t;
    int i,j;

    scanf("%d",&t);

    for (i=0;i<t;++i)
    {
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);

        int comb=1,an=1,bm=1;
        int res;

        for (j=0;j<n;++j)
        {
            an=(an*a)%10007;
        }

        for (j=0;j<m;++j)
        {
            bm=(bm*b)%10007;
        }

        for (j=0;j<n;++j)
        {
            comb=(comb*(k-j))%10007;
        }

        for (j=0;j<n;++j)
        {
            comb=(comb/(n-j))%10007;
        }
        res=(comb*an*bm)%10007;

        printf("case #%d:\n",i);
        printf("%d\n",res);

    }
    return 0;
}