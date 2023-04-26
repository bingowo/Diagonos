#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long jie(int n)
{
    int k=1;
    for(int i=2;i<=n;i++)k=k*i%10007;
    return k;
}

int main()
{
    int k,n,m,a,b,T;long long sum1,sum2,sum;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        sum1=jie(m)*jie(k-m)*(long long)pow(a,n)*(long long)pow(b,m)%10007;
        sum2=jie(k);
        sum=sum2/sum1%10007;
        printf("case #%d\n",t);
        printf("%lld\n",sum);
    }
}
