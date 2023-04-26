#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,y,ans;
    scanf("%lld %lld",&x,&y);
    ans = 0;
    while(x > 0 && y > 0){
        if(y > x){
            int temp;
            temp = x;
            x = y;
            y = temp;
        }
        long long int c;
        c = x / y;
        ans = ans + 4 * y * c;
        x = x - y * c;
    }
    printf("%lld\n",ans);
    return 0;
}
