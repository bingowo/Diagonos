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

        int t1=1,t2=1;
        for (j=0;j<n;++j)
        {
            t1=(t1*(k-j))%10007;
            t2=(t2*(n-j))%10007;
        }
        comb=t1/t2;
        
        res=(comb*an*bm);

        printf("case #%d:\n",i);
        printf("%d\n",res);

    }
    return 0;
}