#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    int cmp(const void*,const void*);
    scanf("%d",&n);
    char **adrs = (char **)malloc(n*sizeof(char*));
    char s[1000001],*p;
    for(int i = 0;i<n;i++){
        scanf("%s",s);
        p = (char *)malloc(strlen(s) + 1);
        strcpy(p,s);
        *(adrs+i) = p;
    }
    qsort(adrs,n,sizeof(char *),cmp);
    return 0;
}
int cmp(const void *a,const void *b)
{
    char *pa = (const char*)a;
    char *pb = (const char*)b;
    int i = 0;
    while(*(*p+i))
    
}