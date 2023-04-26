#include<stdio.h>
#include<string.h>
#define M 100
typedef long long ll;
int main()
{
    int T,i,j,k,m,n;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d %d",&m,&n);
        ll a[42][M]={0};
        a[0][49]=1;
        for(i=1;i<m+1;++i)
        {
            for(j=0;j<M;++j)if(a[i-1][j]==1){a[i][--j]=1;break;}
            k=j;
            j+=2;
            for(j;j<k+2*i-1;j+=2)a[i][j]=a[i-1][j-1]+a[i-1][j+1];
            a[i][j]=1;
        }
        for(i=0;i<M;++i)if(a[m][i])break;
        printf("case #%d:\n%lld\n",cas,a[m][i+n*2]);
    }
    return 0;
}