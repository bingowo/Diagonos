#include <stdio.h>
int divide(int x){
    int cnt = 0;
    while(x%5==0){
        cnt++;
        x/=5;
    }
    return cnt;
}
int main(){
    int t; scanf("%d",&t);
    for(int i = 0; i<t; i++){
        printf("case #%d:\n",i);
        int cnt = 0;
        int n;scanf("%d",&n);
        for(int i = 1; i<=n; i++){
            cnt+=divide(i);
        }
        printf("%d\n",cnt);
    }
    return 0;
}