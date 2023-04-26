#include <stdio.h>

int main()
{
    unsigned long long fib[74]={0,1,1};
    for(int i=3; i<74; ++i)
        fib[i] = fib[i-1] + fib[i-2] + fib[i-3];
    int T;  scanf("%d",&T);
    for(int i=0; i<T; ++i){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%llu\n",i,fib[n]);
    }
    return 0;
}