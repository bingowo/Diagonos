#include <stdio.h>
long long f(long long x)
{
    long long n,p;
    n=0;
    p=1;
    while(x>0){
        n=n+p*(x%10);
        x=x/10;
        p=p*9;
    }
    return n;
}
int main()
{
    long long a,b,n,i,n1,n2;
    scanf("%lld%lld",&a,&b);
    n=f(b)-f(a)+1;
    n1=f(a-a%10)/9;
    for(i=a-a%10;i<a;i++)
        if(i%9==0)
            n1++;
    n2=f(b-b%10)/9;
    for(i=b-b%10;i<b;i++)
        if(i%9==0)
            n2++;
    n=n+n1-n2;
    printf("%lld\n",n);
    return 0;
}
