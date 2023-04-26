#include <stdio.h>
long long int map[51]={0};
long long int solve(int n){
    long long int ret=0;
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    else if(n==4) return 8;
    else{
        if(map[n]!=0) ret = map[n];//先设置一个判断
        else{
            ret=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
            map[n] = ret;
        }
    }
}
int main(){
    map[0]=0,map[1]=1,map[2]=2,map[3]=4,map[4]=8;
    int T = 0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n = 0;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%lld\n",solve(n));
    }
    return 0;
}
