#include <stdio.h>
#include <stdlib.h>
long long int compute(int n);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n;
        scanf("%d",&n);
        long long int ans;
        ans = compute(n);
        printf("case #%d:\n",t);
        if(n == 0){
            printf("0\n");
        }else if (n == 1){
            printf("1\n");
        }else if (n == 2){
            printf("2\n");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}


long long int compute(int n){
    if(n == 0){
        return 0;
    }else if(n == 1 || n == 2){
        return 1;
    }else if(n > 2){
        return compute(n-1) + compute(n-2) + compute(n-3);
    }
}
