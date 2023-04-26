#include<stdio.h>

long long pow(int n){//计算 a的n次方
    long long r;
    if (n==0) r=1;
    if (n==1) r=2;
    r=pow(a, n/2);
    r=r*r
    if (n%2) r=r*2;
    return r;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n;
        scanf("%d",&n);
        long long ans=pow(n);
        printf("case #%d:\n%lld",a,ans);
        a++;
    }
}