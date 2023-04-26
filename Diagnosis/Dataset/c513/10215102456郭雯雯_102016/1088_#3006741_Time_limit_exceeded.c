#include<stdio.h>

long long c(int m,int n){
    int k=m/2;
    if(n>k)n=m-n;
    if(n==0)return 1;
    else if(n==1)return (long long)m;
    else return c(m-1,n)+c(m-1,n+1);
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int m,n;
        scanf("%d %d",&m,&n);
        long long ans=c(m,n);
        printf("case #%d:\n%lld\n",a,ans);
        a++;
    }
}