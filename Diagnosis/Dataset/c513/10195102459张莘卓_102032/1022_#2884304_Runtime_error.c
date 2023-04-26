#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* m, const void *n) {
    char *a = *((char**)m), *b=*((char**)n);
    char *p1 = strchr(a,'@'); *p1 = '\0'; ++p1;
    char *p2 = strchr(b,'@'); *p2 = '\0'; ++p2;
    if(strcmp(p1,p2)){
        *(--p1) = *(--p2) = '@';
       return strcmp(p1,p2);
    } else {
        int t = strcmp(b,a);
        *(--p1) = *(--p2) = '@';
        return t;
    }
}
char s[1000010];

int main()
{
    int n;
    scanf("%d",&n);
    char **a = (char **)malloc(n*sizeof(char*));
    for(int i=0; i<n; ++i) {
        scanf("%s",s);
        a[i] = (char*) malloc(strlen(s));
        strcpy(a[i],s);
    }
    qsort(a,n,sizeof(char*),cmp);
    for(int i=0; i<n; ++i){
        printf("%s\n",a[i]);
        free(a[i]);
    }
    free(a);
    return 0;
}
