#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,j,q,a[200][200];
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
    int num = n>m?m:n,ans = 0;
    for(i = 2;i<=num;i++)
    {
        int n0,m0;
        for(n0=0;n0<=n-i;n0++)
        {for(m0=0;m0<=m-i;m0++)
            {int sum = 0,sum1 = 0,sum2= 0,sum3 = 0,sum4 = 0;
            for(j = 0;j<i;j++)
                {for(q = 0;q<i;q++)
                    {
                        sum += a[n0+j][m0+q];
                        if(j==q) sum1+=a[n0+j][m0+q];
                        if(j<q) sum2+= a[n0+j][m0+q];
                        if(j+q==i-1) sum3+=a[n0+j][m0+q];
                        if(j+q<i-1) sum4+=a[n0+j][m0+q];
                    }
                }
            if(sum>k)
            {
                if(sum-sum2>=k) ans++;
                if(sum1+sum2>=k) ans++;
                if(sum-sum4>=k) ans++;
                if(sum3+sum4>=k) ans++;
            }
            }
        }

    }
    printf("%d\n",ans);
    return 0;



}
