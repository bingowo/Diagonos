#include <stdio.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if (x%2==0 && y%2==0){
        printf("%d",-1);
    }
    return 0;
}
