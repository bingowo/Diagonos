#include<stdio.h>
int main(){
    long long a[51]={0};
    a[1]=1;a[2]=2;a[3]=4;a[4]=8;
    for(int i=5;i<=50;++i)a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    int T;
    scanf("%d\n",&T);
    for(int j=0;j<T;++j){
        int n;scanf("%d\n",&n);
        printf("case #%d:\n",j);
        printf("%lld\n",a[n]);
    }
    return 0;
}