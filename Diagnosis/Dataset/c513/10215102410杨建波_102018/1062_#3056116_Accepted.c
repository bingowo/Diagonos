#include<stdio.h>
long long fun_[50]={0};
long long  fun(int n){
    if(n == 0)return 1;
    if(n < 0)return 0;
    if(fun_[n-1] != 0)return fun_[n-1];
    fun_[n-1] = fun(n-1)+fun(n-2)+fun(n-3)+fun(n-4);
    return fun_[n-1];
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,fun(n));
    }
}