#include <stdio.h>
long long solve(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 4;
    if(n==4)return 8;
    return solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
}
int main() {
    int n;
    scanf("%d",&n);
    int i=0;
    while(n--){
        int d;
        scanf("%d",&d);
        printf("case %d:\n%lld\n",i,solve(d));
        i++;
    }
    return 0;
}
