#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int now = 1;
        int ans = 1;
        while (n > 1){
            if((n&1) != ((n>>1)&1)){
                now++;
            }
            else{
                if (now > ans){
                    ans = now;
                    now = 1;
                } 
            }
            n >>= 1;
        }
        if (now > ans) ans = now;   
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}