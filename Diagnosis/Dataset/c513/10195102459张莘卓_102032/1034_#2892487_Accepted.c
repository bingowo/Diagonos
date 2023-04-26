#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int rank[120];
typedef struct{
    char c;
    double time;
}A;

int cmp(const void* m, const void* n) {
    A *a = (A*)m, *b = (A*)n;
    if(fabs(a->time-b->time) < 1e-12)
        return a->c - b->c;
    else if(b->time > a->time) return 1;
    else return -1;
}

int cmp2(const void* m, const void* n) {
    char a=*((char*)m), b=*((char*)n);
    return rank[a] - rank[b];
}

int main()
{
    int T;  scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        A a[26];
        for(int i=0; i<26; ++i){
            a[i].c = 'A' + i;
            scanf("%lf",&a[i].time);
        }
        qsort(a, 26, sizeof(A), cmp);
        for(int i=0; i<26; ++i){
            rank[a[i].c] = 2*i + 1;
            rank[a[i].c+32] = 2*i;
        }
        char s[101];
        scanf("%s",s);
        qsort(s, strlen(s), sizeof(char), cmp2);
        printf("case #%d:\n%s\n",j,s);
    }
    return 0;
}
