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
        int now = 0;
        int ans = 0;
        while (n > 0){
            if((n&1) != ((n>>1)&1)){
                now++;
            }
            else{
                if (now > ans){
                    ans = now;
                    now = 0;
                } 
            }
            n >>= 1;
        }
        if (now > ans) ans = now;   
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}