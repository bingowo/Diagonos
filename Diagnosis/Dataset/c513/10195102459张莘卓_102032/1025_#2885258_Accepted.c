#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[21];
    int cnt;
}string;

int cmp(const void* m, const void* n){
    string *a=(string*)m, *b = (string*)n;
    if(a->cnt != b->cnt)
        return b->cnt - a->cnt;
    else
        return strcmp(a->s,b->s);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n; scanf("%d",&n);
        string a[100];
        for(int i=0; i<n; ++i) {
            a[i].cnt = 0;
            scanf("%s",a[i].s);
            int alpha[128] = {0};
            for(int k=0; a[i].s[k]; ++k) {
                if(alpha[a[i].s[k]]==0){
                    ++a[i].cnt;
                    alpha[a[i].s[k]] = 1;
                }
            }
        }
        qsort(a,n,sizeof(string),cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<n; ++i)
            printf("%s\n",a[i].s);
    }
    return 0;
}
