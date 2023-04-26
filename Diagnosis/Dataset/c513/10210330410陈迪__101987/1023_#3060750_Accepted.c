#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    char str[31];
    int n;
} S;
int cmp(const void *a, const void *b)
{
    S *p1 = (S *)a, *p2 = (S *)b;
    if (p1->n == p2->n)
        return strcmp(p1->str,p2->str);
    return p1->n - p2->n;
}
int main()
{
    S s[256];
    int n = 0;
    while(scanf("%s",s[n].str)!=EOF) {
        s[n].n = -1;
        for(int i=0, l = strlen(s[n].str); i<l; ++i) {
            if(isdigit(s[n].str[i])) {
                s[n].n = atoi(s[n].str+i);
                break;
            }
        }
        n++;
    }
    qsort(s, n, sizeof(s[0]),cmp);
    for (int i=0; i<n-1; ++i)
        printf("%s ",s[i].str);
    printf("%s\n",s[n-1].str);
    return 0;
}
