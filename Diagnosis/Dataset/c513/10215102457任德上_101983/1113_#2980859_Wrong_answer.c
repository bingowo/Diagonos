#include<stdio.h>
int main(){
    long long int k,m,num[200]={0LL};
    scanf("%lld%lld",&k,&m);
    num[12]=1LL;
    m=m+10LL;
    for(int i=13;i<=m;i++){
        for(int p=i-k;p<i;p++){
            num[i]+=num[p];
        }
    }
    printf("%lld",num[m]);
    return 0;
}