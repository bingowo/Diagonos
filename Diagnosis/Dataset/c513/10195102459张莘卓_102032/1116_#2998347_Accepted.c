#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x, y, sum;
    scanf("%lld %lld",&x, &y);
    sum = llabs(x) + llabs(y);
    if(sum % 2 == 0) printf("%d\n",sum ? -1 : 0);
    else {
        int cnt = 0;
        while(sum) {
            ++cnt;
            sum /= 2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
