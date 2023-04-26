#include <stdio.h>
#include <stdlib.h>
//迭代
long long f(int n){
    static long long a[51];
    a[0]=1;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<=50;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    return a[n];
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        printf("case #%d:\n""%lld\n",i,f(n));
    }
    return 0;
}
