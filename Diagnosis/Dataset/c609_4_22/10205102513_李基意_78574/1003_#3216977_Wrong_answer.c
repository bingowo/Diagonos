#include <stdio.h>
#include <stdlib.h>



int main() {
    int t;
    int w=2333;
    scanf("%d",&t);
    while(t--){
        long long int n;
        int ans[1000],number=0;
        scanf("%lld",&n);
        while(n){
            ans[number]=n%w;
            n/=w;
            number++;
        }
        for(int i=number-1;i>0;i--){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[0]);
    }
    return 0;

}