#include<stdio.h>
int main(){
    long long int num[200]={0LL};
    int k,m;
    scanf("%d%d",&k,&m);
    num[12]=1LL;
    m=m+10;
    for(int i=13;i<=m;i++){
        for(int p=i-k;p<i;p++){
            num[i]+=num[p];
        }
    }
    printf("%lld",num[m]);
    return 0;
}