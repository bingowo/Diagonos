#include <stdio.h>
#include <stdlib.h>

long long int Tribonacci(int n)
{
    //用递归会超时
//    if(n == 0 || n == 1)
//        return n;
//    else if (n == 2)
//        return 1;
//    else return Tribonacci(n-1)+Tribonacci(n-2)+Tribonacci(n-3);

//迭代
    long long int a[75];
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    int i=0;
    for(i=3;i<=n;i++)
    {
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    return a[n];
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",Tribonacci(n));
    }
    return 0;
}