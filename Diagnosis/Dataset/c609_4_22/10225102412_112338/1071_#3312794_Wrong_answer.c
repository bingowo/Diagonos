#include <stdio.h>

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if (x%2==y%2 || x==y){
        printf("%d",-1);
    }
    return 0;
}
