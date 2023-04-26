#include<stdio.h>
#include<stdlib.h>

long long cmp(const void* a,const void* b){
    long long m=*(long long *)a,n=*(long long *)b,t;
    t=n-m;
    return t;
}
long long min(long long a,long long b){
    if(a>b)return b;
    return a;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    long long num[n],sum=0,ans=0;
    for(int i=0;i<n;i++)scanf("%lld",&num[i]);
    qsort(num,n,sizeof(long long),cmp);
    for(int i=0;i<n;i++)printf("%lld ",num[i]);
    for(int i=n-1;i>(n-m);i--)sum+=(num[0]-num[i]);
    for(int i=0;i<=n-m;i++){
        for(int j=i+1;j<i+m;j++)ans+=(num[i]-num[j]);
        sum=min(sum,ans);
        ans=0;
    }
    printf("%lld",sum);
}