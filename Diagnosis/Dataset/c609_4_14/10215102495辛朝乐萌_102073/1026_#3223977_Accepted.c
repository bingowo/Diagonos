#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char s[21];
    int num[26];
    int kind;
}word;

int count(word w)
{
    char *p=w.s;
    int ret=0;
    while (*p) {
        if(w.num[*p-'A']==0){
            w.num[*p-'A'] = 1;
            ret+=1;
        }
        p++;
    }
    return ret;
}

int cmp(const void *a,const void *b)
{
    word *pa=(word *)a;
    word *pb=(word *)b;
    if(pa->kind!=pb->kind){
        return pb->kind-pa->kind;
    }
    else{return strcmp(pa->s, pb->s);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int n;
        scanf("%d",&n);
        word input[n];
        for (int j=0; j<n; j++) {
            scanf("%s",input[j].s);
            memset(input[j].num, 0, sizeof(int)*26);
            input[j].kind=count(input[j]);
        }
        qsort(input, n, sizeof(word), cmp);
        printf("case #%d:\n",i);
        for (int j=0; j<n; j++) {
            printf("%s\n",input[j].s);
        }
    }
    return 0;
}