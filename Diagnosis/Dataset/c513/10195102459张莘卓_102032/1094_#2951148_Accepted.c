#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* m, const void* n) {
    char *a = *(char**)m, *b = *(char**)n;
    int sign = 1;
    if(*a=='-' && *b=='-') {
        ++a;  ++b;  sign = -1;
    }else if(*a == '-') return -1;
    else if(*b == '-') return 1;
    if(strlen(a) > strlen(b)) return sign;
    else if(strlen(a) == strlen(b))
        return sign * strcmp(a, b);
    return -sign;
}

int makeNumber(char* s, int* num) {
    int p = strlen(s) - 1;
    for(int i=0; isdigit(s[p-i]); ++i)
        num[i] = s[p-i] - '0';
    return *s == '-' ? -1 : 1;
}

void compare(char* n1, char* n2) {
    
}

int main()
{
    int n;
    scanf("%d",&n);
    char** s = (char**) malloc(n*sizeof(char*));
    for(int i=0; i<n; ++i) {
        s[i] = (char*) malloc(121*sizeof(char));
        scanf("%s",s[i]);
    }
    qsort(s, n, sizeof(char*), cmp);
    
    int n1[121] = {0}, n2[121] = {0}, s1, s2;
    if(s[0][0]=='-' && s[n-1][0]=='-'){
        s1 = makeNumber(s[0], n1);
        s2 = makeNumber(s[n-1], n2);
    }else{
        s1 = makeNumber(s[n-1], n1);
        s2 = makeNumber(s[0], n2);
    }
    if(s1 == s2) {
        for(int i=0; i<121; ++i) {
            if(n1[i] < n2[i]) {
                n1[i] += 10;
                int k = i + 1;
                while(n1[k] == 0) n1[k++] +=9 ;
                --n1[k];
            }
            n1[i] -= n2[i];
        }
    }else {
        int carry = 0;
        for(int i=0; i<121; ++i){
            n1[i] += n2[i] + carry;
            carry = n1[i] / 10;
            n1[i] %= 10;
        }
    }
    int i = 120;
    while(n1[i] == 0) --i;
    if(i < 0) printf("0");
    else for(; i>=0; --i) printf("%d",n1[i]);
    printf("\n");
    for(int i=0; i<n; ++i) free(s[i]);
    free(s);
    return 0;
}