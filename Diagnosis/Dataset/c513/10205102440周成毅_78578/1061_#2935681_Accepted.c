#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char s[16];
    long long number;
} string;

void trans(string *target) {
    int a[128] ;for(int i=0;i<128;i++) a[i]=-1;
    int R = 0;
    char *p = target->s;
    a[*p] = 1;
    while (*++p)
        if (a[*p] == -1) {
            a[*p] = R;
            R = R ? R + 1 : 2;
        }
    if (R < 2) R = 2;
    long long N = 0;
    p = target->s;
    while (*p)
        N = N * R + a[*p++];
    target->number = N;
}

int cmp(const void *a, const void *b){
    string *a1=(string *)a;
    string *b1=(string *)b;
    if(a1->number!=b1->number)
        return a1->number>b1->number? 1:-1;
    else
        return strcmp(a1->s,b1->s);
}

int main() {
    int T;
    scanf("%d", &T);
    string *p = (string *) malloc(sizeof(string) * T);
    for (int i = 0; i < T; i++) {
        scanf("%s", p[i].s);
        trans(&p[i]);
    }
    qsort(p,T,sizeof (string),cmp);
    for(int i=0;i<T;i++)
        printf("%s\n",p[i].s);
    return 0;
}
