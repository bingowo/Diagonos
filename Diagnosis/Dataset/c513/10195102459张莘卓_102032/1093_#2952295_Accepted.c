#include <stdio.h>
#include <string.h>

int find9(int* a, int len) {
    for(int i=len-1; i>=0; --i)
        if(a[i] == 9) return i;;
    return -1;
}

void elimate9(int* a, int* p) {
    int i, len = *p;
    if((i = find9(a, *p)) != -1) {
        int carry = 1;
        for(int k=0; k<i; ++k) a[k] = 0;
        for(; i<len; ++i) {
            a[i] += carry;
            carry = a[i] / 10;
            a[i] %= 10;
            if(carry == 0) break;
        }
        if(carry) a[len++] = carry;
    }
    *p = len;
}

void plus(int* a, int carry, int* p) {
    for(int i=0; i<*p; ++i) {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
        if(carry == 0) break;
    }
    if(carry) a[(*p)++] = carry;
}

int main()
{
    char s[101];
    scanf("%s",s);
    int len=strlen(s), a[111] = {0};
    for(int i=0; i<len; ++i) a[i] = s[len-1-i] - '0';
    plus(a, 1, &len);
    do{
        elimate9(a, &len);
        int sum = 0;
        for(int i=0; i<len; ++i) sum += a[i];
        sum = sum % 9 ? 0 : 1;
        plus(a, sum, &len);
    }while(find9(a, len) != -1);
    int i = 110;
    while(i>=0 && a[i] == 0) --i;
    for(; i>=0; --i) printf("%d",a[i]);
    printf("\n");
    return 0;
}
