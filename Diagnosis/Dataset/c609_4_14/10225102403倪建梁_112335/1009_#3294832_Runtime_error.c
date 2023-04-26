#include <stdio.h>
#include <string.h>
int count_bits(char c) {
    int count = 0;
    while (c) {
        c=c&(c-1);
        count++;
    }
    return count;
}

int gcd(int x, int y) {
    int r;
    do{ r = x%y;
        x=y;
        y=r;
    }while(r);
    return x;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[121];
        gets(s);
        int len = strlen(s); 
        int count = 0;
        for (int j = 0; j < len; j++) {
            count += count_bits(s[j]);
        }
        len=len*8;int a=gcd(count,len);
        printf("%d/%d\n",count/a,len/a);
    }
    return 0;
}
