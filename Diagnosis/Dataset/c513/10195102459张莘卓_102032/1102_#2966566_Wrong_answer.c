#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, x, y;
    scanf("%d",&n);
    int temp = (int) sqrt(n);
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
    printf("(%d,%d)\n",x,y);
    return 0;
}
