#include<stdio.h>
#include<stdlib.h>
//static

//a[n] 保留运算结果
long long step(int n){
    static long long a[51];
    if(n < 0) return 0;
    if(n == 0) return a[n] = 1;
    if(!a[n]){
        return a[n] = step(n-1)+step(n-2)+step(n-3)+step(n-4);
    }
    return a[n];
}

int main(void)
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i<T; i++){
        int n;
        scanf("%d",&n);

        long long out = 0;
        out = step(n);

        printf("case #%d:\n",i);
        printf("%lld\n",out);
    }
    return 0;
}