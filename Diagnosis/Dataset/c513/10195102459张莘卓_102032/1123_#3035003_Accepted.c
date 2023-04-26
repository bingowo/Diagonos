#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[21];
    int cnt;
}DNA;
DNA d[200000];

int cmp(const void* pa, const void* pb) {
    return strcmp(*(char**)pa, *(char**)pb);
}

int cmp2(const void* pa, const void* pb) {
    DNA *a=(DNA*)pa, *b=(DNA*)pb;
    if(a->cnt != b->cnt) return a->cnt - b->cnt;
    else return strcmp(a->data, b->data);
}

int main()
{
    int n;
    scanf("%d",&n);
    char** a = (char**)malloc(n*sizeof(char*));
    for(int i=0; i<n; ++i) {
        a[i] = (char*) malloc(21*sizeof(char));
        scanf("%s",a[i]);
    }
    qsort(a, n, sizeof(char*), cmp);
    int cnt = 0, i=0;
    while(i < n) {
        strcpy(d[cnt].data, a[i++]);
        d[cnt].cnt = 1;
        while(i<n && strcmp(d[cnt].data, a[i])==0){
            ++d[cnt].cnt;
            ++i;
        }
        ++cnt;
    }
    qsort(d, cnt, sizeof(d[0]), cmp2);
    for(i=0; i<cnt; ++i) puts(d[i].data);
    for(i=0; i<n; ++i) free(a[i]);
    free(a);
    return 0;
}
