#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 503

int swap(char* a, char* b) {
    char* t = (char*)malloc(N*sizeof(char));
    strcpy(t, a);  strcpy(a, b);  strcpy(b, t);
    free(t);
    return -1;
}

void process(char* s) {
    char* p = strchr(s, '.');
    int len = strlen(s);
    if(p == NULL) {
        s[len] = '.'; s[len+1] = '0'; s[len+2] = '\0';
    }else if(*(p+1) == '\0') {
        s[len] = '0'; s[len+1] = '\0';
    }else if(p == s) {
        char* t = malloc(N*sizeof(char));
        t[0] = '0';  t[1] = '\0';
        strcat(t, s);  strcpy(s, t);
    }
}

int compare(char*a, char *b) {
    process(a);  process(b);
    char *p1 = strchr(a, '.'), *p2 = strchr(b, '.');
    *p1 = *p2 = '\0';
    if(strlen(a) < strlen(b)) {
        *p1 = *p2 = '.';
        return swap(a, b);
    }else if(strlen(a) == strlen(b)){
        if(strcmp(b, a) > 0){
            *p1 = *p2 = '.';
            return swap(a, b);
        }else if(strcmp(b, a) == 0) {
            if(strcmp(p2+1, p1+1) > 0){
                *p1 = *p2 = '.';
                return swap(a, b);
            }
        }
    }
    *p1 = *p2 = '.';
    return 1;
}

void set(char* s, int* a) {
    char* p = strchr(s, '.');
    for(int i=0; p-i>s; ++i)
        a[N+i] = *(p-i-1) - '0';
    for(int i=1; *(p+i); ++i)
        a[N-i] = *(p+i) - '0';
}

void minus(int* a, int* b) {
    int len = 2*N;
    while(a[len-1]==0) --len;
    for(int i=0; i<len; ++i) {
        if(a[i] < b[i]) {
            a[i] += 10;
            int k = i + 1;
            while(a[k] == 0) a[k++] = 9;
            --a[k];
        }
        a[i] -= b[i];
    }
}

int main()
{
    char n1[N], n2[N];
    scanf("%s %s",n1,n2);
    int sign = compare(n1, n2);
    int i=2*N-1, a[2*N] = {0}, b[2*N] = {0}, n;
    scanf("%d",&n);
    set(n1, a); set(n2, b);
    minus(a, b);
    if(a[N-1-n] > 4) {
        int carry = 1, k = N-n;
        while(carry) {
            int t = a[k] + carry;
            a[k++] = t % 10;
            carry = t / 10;
        }
    }
    while(i>=N && a[i] == 0) --i;
    if(sign == -1) printf("-");
    if(i < N) printf("0");
    else for(; i>=N; --i) printf("%d",a[i]);
    printf(".");
    for(int i=1; i<=n; ++i) printf("%d",a[N-i]);
    printf("\n");
    return 0;
}
