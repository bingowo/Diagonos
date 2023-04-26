#include <stdio.h>
#include <stdlib.h>

void ito2333(long long int n);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        long long int n;
        scanf("%lld",&n);
        ito2333(n);
    }
    return 0;
}


void ito2333(long long int n){
    int ans[500];
    //a / 2333 = b .....c
    long long int a,b,c;
    int cnt = 0;
    a = n;
    if(a != 0){
        while(a != 0){
            b = a / 2333;
            c = a % 2333;
            a = b;
            ans[cnt] = c;
            cnt++;
        }
    }else if(a == 0){
        cnt = 1;
        ans[0] = 0;
    }
    for(int i = cnt - 1; i > 0; i--){
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[0]);
}
