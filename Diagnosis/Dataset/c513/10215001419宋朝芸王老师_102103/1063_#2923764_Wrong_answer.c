#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,y,ans = 0,temp,a,b;
    scanf("%lld%lld",&x,&y);

    if(x == y){
        printf("%lld",4*x);
        return 0;
    }

    if(x < y){
        temp = x; x = y; y = temp;
    }

    while(y > 0){
        a = x/y;
        b = x%y;
        ans += 4 * y * a;
        x = x - a * y;
        y = b;

        if(x < y){
        temp = x; x = y; y = temp;
        }
    }

    printf("%lld",ans);

    return 0;
}
