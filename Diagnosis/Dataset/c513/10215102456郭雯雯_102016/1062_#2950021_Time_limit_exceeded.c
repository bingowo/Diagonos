#include<stdio.h>

long long f(int n){
    long long t;
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 4;
    if(n==4)return 8;
    if(n>4)return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}
int main(){
    int t,n,a=0;
    scanf("%d",&t);
    while(a<t){
        scanf("%d",&n);
        long long num=f(n);
        printf("case #%d:\n%lld\n",a,num);
        a++;
    }
    return 0;
}