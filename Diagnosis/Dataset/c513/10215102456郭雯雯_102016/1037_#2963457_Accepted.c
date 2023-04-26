#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    long long m=*(long long *)a,n=*(long long *)b;
    if(n>m)return 1;
    return -1;
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
    qsort(num,n,sizeof(long long),cmp);//降序排列
    for(int i=1;i<m;i++)sum+=(num[0]-num[i]);
    ans=sum;
    for(int i=1;i<=n-m;i++){
        ans-=(num[i-1]-num[i])*m;
        ans+=num[i-1]-num[i+m-1];
        sum=min(sum,ans);
    }
    printf("%lld",sum);
}