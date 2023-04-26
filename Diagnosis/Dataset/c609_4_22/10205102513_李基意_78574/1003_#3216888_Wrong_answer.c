#include <stdio.h>
#include <stdlib.h>



int main() {
    int t;
    int w=2333;
    long long int n;
    scanf("%d",&t);
    while(t--){
        int ans[1000],number=0;
        scanf("%lld",&n);
        while(n){
            ans[number]=n%w;
            n/=w;
            number++;
        }
        for(int i=number;i>0;i--){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[0]);
    }
    return 0;

}
