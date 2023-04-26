#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x, y, sum;
    scanf("%lld %lld",&x, &y);
    char px[2] = {'W','E'}, py[2] = {'S','N'};
    if(x < 0) {
        px[0] = 'E';  px[1] = 'W';
    }
    if(y < 0) {
        py[0] = 'N';  py[1] = 'S';
    }
    x = llabs(x);  y = llabs(y);
    sum = x + y;
    if(sum % 2 == 0) {
        printf("%d",sum ? -1 : 0);
        return 0;
    }
    
    int bin[64], cnt = 0;
    for(; sum; ++cnt) {
        bin[cnt] = sum % 2;
        sum /= 2;
    }
    printf("%d\n",cnt);
    for(int i=1; i<cnt; ++i)
        if(bin[i] == 0) {
            bin[i-1] = -1;
            bin[i] = 1;
        }
    
    for(int i=0; i<cnt; ++i) {
        if(bin[i] == 1) {
            printf("%c",x%2 ? px[1] : py[1]);
        }else{
            printf("%c", x%2? px[0] : py[0]);
            x%2 ? ++x : ++y;
        }
        x /= 2;  y /= 2;
    }
    printf("\n");
    return 0;
}
