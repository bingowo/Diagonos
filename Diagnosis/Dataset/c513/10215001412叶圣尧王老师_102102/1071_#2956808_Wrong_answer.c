#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int jie(int n)
{
    int k=1;
    for(int i=2;i<=n;i++)k=k*i%10007; 
    return k;
}

int main()
{
    int k,n,m,a,b,T;int sum1,sum2,sum;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        sum1=jie(n)*jie(k-n)%10007;
        sum2=jie(k);
        if(sum1<=sum2)sum=sum2/sum1%10007;
        else sum=(sum2+10007)/sum1%10007;
        printf("case #%d\n",t);
        printf("%d\n",sum);
    }
}