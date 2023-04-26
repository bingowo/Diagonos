#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long n, x, y;
    scanf("%lld",&n);
    long long temp = (long long) sqrt(n);
    if(temp % 2) {
        x = temp / 2;   y = x + 1;
        if(n - temp*temp <= temp) x -= n - temp*temp;
        else {
            x -= temp;
            y -= n - temp*(temp+1);
        }
    }else {
        x = y = -temp / 2;
        if(n - temp*temp <= temp) x += n - temp*temp;
        else {
            x += temp;
            y += n - temp * (temp+1);
        }
    }
    printf("(%lld,%lld)\n",x,y);
    return 0;
}
