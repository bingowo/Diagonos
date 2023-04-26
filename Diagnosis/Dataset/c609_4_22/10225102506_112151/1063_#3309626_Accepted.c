#include <stdio.h>
#include <stdlib.h>
//递归
long long f(int n){
    static long long a[51];
    if(n<0) return 0;
    if(!a[n]) a[n]=n?f(n-1)+f(n-2)+f(n-3)+f(n-4):1;
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
