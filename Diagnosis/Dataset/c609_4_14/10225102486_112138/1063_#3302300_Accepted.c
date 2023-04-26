#include<stdio.h>

long long cnt[52]={0,1,2,4,8};

long long solveStep(int n){

    if(cnt[n]!=0)
        return cnt[n];
    else if(n>4){
        cnt[n]=solveStep(n-4)+solveStep(n-3)+solveStep(n-2)+solveStep(n-1);
        return cnt[n];
    }
}

int main(){
    int T,n;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",t,solveStep(n));
    }
    return 0;
}
