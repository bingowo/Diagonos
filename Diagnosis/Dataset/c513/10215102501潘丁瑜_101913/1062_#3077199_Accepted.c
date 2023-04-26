#include <stdio.h>
#include <stdlib.h>

//long long f(long long a)
//{
//    if(a == 0)
//    {
//        return 1;
//    }
//    if(a == 1)
//    {
//        return 1;
//    }
//    if(a == 2)
//    {
//        return 2;
//    }
//    if(a == 3)
//    {
//        return 4;
//    }
//    return (f(a - 1) + f(a - 2) + f(a - 3) + f(a - 4));
//}
long long int f(int n)
{
    if(n == 2 || n== 1)
        return n;
    if(n == 3)
        return 4;
    if(n == 0)
        return 1;
    long long int a=1,b=1,c=2,d=4,e=0,i;
    for(i=4;i<=n;i++)
    {
        e = a+b+c+d;
        a=b;
        b=c;
        c=d;
        d=e;
    }
    return e;
}

int main()
{
    int t,i,n;
    long long int r;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        r=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",r);
    }
    return 0;
}