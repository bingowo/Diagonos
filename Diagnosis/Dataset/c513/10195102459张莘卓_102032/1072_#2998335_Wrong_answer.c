#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bintrans(int* a, long long n) {
    int i = 0;
    do{
        a[i++] = n % 2;
        n /= 2;
    }while(n);
    return i;
}

void plus1(int* a, int pos) {
    int carry = 1;
    while(carry) {
        carry = (a[pos]+1) / 2;
        a[pos] = (a[pos]+1) % 2;
    }
}

int main()
{
    long long x, y, sum;
    scanf("%lld %lld",&x, &y);
    sum = llabs(x) + llabs(y);
    if(sum % 2 == 0) {
        printf("%d\n",sum ? -1 : 0);
        return 0;
    }
    int a[64]={0}, b[64]={0}, t[64]={0}, cnt=0;
    bintrans(a, x);  bintrans(b, y);
    cnt = bintrans(t, llabs(x)+llabs(y));
    printf("%d\n",cnt);
    for(int i=1; i<cnt; ++i)
        if(t[i] == 0) {
            t[i-1] = -1;
            t[i] = 1;
        }
    for(int i=0; i<cnt; ++i) {
        if(t[i] == 1)  printf("%c",a[i] ? 'E':'N');
        else {
            printf("%c",a[i] ? 'W':'S');
            plus1(a[i] ? a : b, i+1);
        }
    }
    printf("\n");
    return 0;
}