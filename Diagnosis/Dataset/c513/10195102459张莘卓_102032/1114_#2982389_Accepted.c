#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void catchNumbers(int* pa, int* pb, int* pc) {
    int i = 0;  char s[20];
    scanf("%s",s);
    while(s[i]) {
        int flag = 1;
        if(s[i]=='+' || s[i]=='-') {
            if(s[i] == '-') flag = -1;
            ++i;
        }
        int sum = 0;
        if(s[i] == 'x') sum = 1;
        else for(; isdigit(s[i]); ++i)
            sum = sum * 10 + s[i] - '0';
        if(s[i] != 'x') {
            *pc = sum * flag; ++i;
        }else if(s[i+1] != '^'){
            *pb = sum * flag;  ++i;
        }else {
            *pa = sum * flag;  i += 3;
        }
    }
}

void GCD(int* pa, int* pb) {
    int a = abs(*pa), b = abs(*pb);
    while(b) {
        int t = b;
        b = a % b;
        a = t;
    }
    *pa /=  a;  *pb /= a;
}

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int main()
{
    int a = 0, b = 0, c = 0;
    catchNumbers(&a, &b, &c);
    int delta = b*b - 4*a*c;
    if(delta < 0) {
        printf("No Answer!\n");
    }else {
        int t = (int)sqrt(delta);
        while(t*t < delta) ++t;
        while(t*t > delta) --t;
        int a1 = 2*a, a2 = 2*a;
        int c1 = b-t, c2 = b+t;
        GCD(&a1, &c1); GCD(&a2, &c2);
        if(a1>a2 || (a1==a2 && c1>c2)){
            swap(&a1, &a2);
            swap(&c1, &c2);
        }
        printf("%d %d %d %d\n",a1,c1,a2, c2);
    }
    return 0;
}
