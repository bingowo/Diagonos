#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char plus[2], minus[2];

int main()
{
    long long x, y;
    scanf("%lld %lld",&x, &y);
    if(x==0 && y==0) {
        printf("0\n");
        return 0;
    }
    if(x < 0) {
        plus[0] = 'W'; minus[0] = 'E';
    }else{
        plus[0] = 'E'; minus[0] = 'W';
    }
    if(y < 0){
        plus[1] = 'S'; minus[1] = 'N';
    }else{
        plus[1] = 'N'; minus[1] = 'S';
    }
    x = llabs(x);  y = llabs(y);
    long long n = x + y;
    if(n % 2 == 0) {
        printf("-1\n");
        return 0;
    }
    int binary[64] = {0}, k = 0;
    while(n) {
        binary[k++] = n % 2;
        n /= 2;
    }
    for(int i=0; i<k; ++i){
        if(binary[i] == 0){
            binary[i-1] = -1;
            binary[i] = 1;
        }
    }
    printf("%d\n",k);
    for(int i=0; i<k; ++i){
        if(x % 2){
            if(binary[i] == 1) printf("%c",plus[0]);
            else printf("%c",minus[0]);
            x -= binary[i];
        }else{
            if(binary[i] == 1) printf("%c",plus[1]);
            else printf("%c",minus[1]);
            y -= binary[i];
        }
        x /= 2;  y /= 2;
    }
    printf("\n");
    return 0;
}
