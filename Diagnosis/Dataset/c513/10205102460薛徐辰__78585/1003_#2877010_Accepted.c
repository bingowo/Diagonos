#include<stdio.h>
#include<stdlib.h>
int change(long long n){
    long long b=n;
    int a=0;
    for(int i=0;i<64;i++){
        a+=(b&1);
        b=b>>1;
    }
    return a;
}
int cmp(const void *a,const void *b){
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    int m;
    if(x>y)m=1;
    else m=-1; 
    if(change(x)==change(y))return m;
    else return change(y)-change(x);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;long long s[100001];
        scanf("%d",&k);
        for(int j=0;j<k;j++)scanf("%lld",&s[j]);
        qsort(s,k,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<k;j++)printf("%lld ",s[j]);
        printf("\n");
    }
    return 0;
}