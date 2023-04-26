#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int jc[1005];
long long power(int a,int n)
{
    long long k=a;
    for(int i=1;i<n;i++)k=k*a%10007;
    if(n==0)k=1;
    return k;
}
long long C(int n,int m)
{
    if(n==m)return 1;
    if(m==0)return 1;
    return ((jc[n]*power(jc[m],10005))%10007*power(jc[n-m],10005))%10007;
}
int main()
{
    int k,n,m,a,b,T;long long p1,p2,p3,p;
    scanf("%d",&T);
    jc[1]=1;
    for(int t=0;t<T;t++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        for(int i=2;i<=k;i++)
            jc[i]=(jc[i-1]*i)%10007;
        int d;d=m>n? n:m;
        p1=C(k,d);
        p2=power(a,n);
        p3=power(b,m);
        p=(p1%10007*p3%10007)%10007*p2%10007;
        printf("case #%d:\n",t);
        printf("%lld\n",p);
    }
}
