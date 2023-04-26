#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *u, *h;
} Email;

int cmp(const void *a, const void *b) {
    const Email *c=a, *o=b;
    int f = strcmp(c->h,o->h);
    if(f!=0) return f;
    else return -strcmp(c->u, o->u);
}

int main() {
    int T;
    scanf("%d",&T);
    getchar();

    Email *v = malloc(T*sizeof(Email));
    Email *p = v;

    char *buf = malloc(sizeof(char)*2000000);
    char *prev=buf, *next=buf;
    for(int i=0; i<T; i++)
    {
        char c;
        int len=0;
        while(scanf("%c",&c)!=EOF && c!='\n') {
            *next++ = c;
            len++;
        }
        *next++ = '\0';
        char* at = strchr(prev,'@');
        *at = '\0';
        p->u = prev;
        p->h = at+1;
        p++;
        prev = next;
    }
    qsort(v, T, sizeof(Email), cmp);
    for(int i=0; i<T; i++) {
        printf("%s@%s\n", v[i].u, v[i].h);
    }
    return 0;
}

