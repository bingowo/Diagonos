#include <stdio.h>
#include <stdlib.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n;
        long long int ans;
        scanf("%d",&n);
        if(n == 0){
            ans = 0;
        }else if(n == 1){
            ans = 1;
        }else if (n == 3){
            ans = 2;
        }else{
            long long int first = 1;
            long long int second = 1;
            long long int third = 2;
            long long int fourth;
            long long int count = 4;
            while(count <= n){
                count++;
                fourth = first + second + third;
                first = second;
                second = third;
                third = fourth;
                ans = fourth;
            }
        }
        printf("case #%d:\n",t);
        printf("%lld\n",ans);


    }
}
