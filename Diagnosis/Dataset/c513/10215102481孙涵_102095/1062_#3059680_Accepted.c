#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int n;
        scanf("%d",&n);
        long long int a,b,c,d,ans,count;
        a = 1;
        b = 2;
        c = 4;
        d = 8;
        count = 5;
        if(n == 1){
            ans = 1;
        }else if(n == 2){
            ans = 2;
        }else if (n == 3){
            ans = 4;
        }else if(n == 4){
            ans = 8;
        }else{
            while(count <= n){
                ans = a + b + c+ d;
                a = b;
                b = c;
                c = d;
                d = ans;
                count++;
            }
        }
        printf("case #%d:\n",t);
        printf("%lld\n",ans);
    }
    return 0;
}
