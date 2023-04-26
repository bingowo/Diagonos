#include<stdio.h>
long long int ans[501];

long long int f(int n){
    if(ans[n]!=-1)return ans[n];
    else if(ans[n]==-1){
        return f(n-1)+f(n-2)+f(n-4);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    memset(ans,-1,sizeof(ans));
    ans[0]=0;ans[1]=1;ans[2]=2;ans[3]=3;ans[4]=4;
    if(n>4)ans[n]=f(n);
    printf("%lld",ans[n]);
    return 0;
}