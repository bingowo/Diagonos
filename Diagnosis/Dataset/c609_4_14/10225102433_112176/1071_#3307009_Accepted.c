#include <stdio.h>
#include <math.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long key = labs(x)+labs(y);
    if(x == 0 && y == 0) printf("0");
    else if(key % 2){
        long long int ans = log(key-1)/log(2)+1;
        printf("%lld",ans);
    }
    else printf("-1");
    return 0;
}