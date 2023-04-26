#include <stdio.h>
#include <string.h>

long long a[1005]={0};
long long b[500505]={0};//b是子数组的和
int cmp(const void*p,const void*q)
{
    long long* a=(long long*)p;long long* b=(long long*)q;return(*a>*b?1:-1);
}

int main()
{
    int T;scanf("%d",&T);
    int n,m,l,u;
    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]=a[i]+a[i-1];//这样a中存储的就是前面元素的和
        }
        int k=0;
        for(int len=1;len<=n;len++)//子串的长度
        {
            for(int i=1;i<=n-len+1;i++)//这样长度的子串有多少个
                b[++k]=a[i+len-1]-a[i-1];//存放每一个子数组的和
        }
        qsort(b+1,k,sizeof(b[0]),cmp);
        for(int i=1;i<=k;i++)b[i]+=b[i-1];//b存储的也是前面元素的和
        printf("case #%d:\n",cas);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&l,&u);
            printf("%lld\n",b[u]-b[l-1]);
        }
    }
    return 0;
}
