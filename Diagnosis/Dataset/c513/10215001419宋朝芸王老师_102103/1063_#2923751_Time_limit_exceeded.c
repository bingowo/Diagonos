#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,y,ans = 0,temp;
    scanf("%lld%lld",&x,&y);

    if(x == y){
        printf("%lld",4*x);
        return 0;
    }

    if(x < y){
        temp = x; x = y; y = temp;
    }

    while(y > 0){
        ans += 4 * y;
        x = x - y;

        if(x < y){
        temp = x; x = y; y = temp;
        }
    }

    printf("%lld",ans);

    return 0;
}
