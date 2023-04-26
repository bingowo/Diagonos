#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* pa, const void* pb) {
    char *a=*(char**)pa, *b=*(char**)pb;
    int i = 7;
    while(a[i]==b[i] && a[i]!='/') ++i;
    if(a[i]==b[i]) return strcmp(a, b);
    else if(a[i] == '/') return -1;
    else if(b[i] == '/') return 1;
    else return a[i] - b[i];
}



int main()
{
    int n, cnt=0;
    scanf("%d",&n);
    char** s = (char**)malloc(n*sizeof(char*));
    for(int i=0; i<n; ++i) {
        char t[301];
        scanf("%s",t);
        if(strstr(t, "http://")!=NULL) {
            s[cnt] = (char*)malloc(301*sizeof(char));
            strcpy(s[cnt++], t);
        }
    }
    qsort(s, cnt, sizeof(char*), cmp);
    for(int i=0; i<cnt; ++i) {
        printf("%s\n",s[i]);
        free(s[i]);
    }
    free(s);
    return 0;
    
}
