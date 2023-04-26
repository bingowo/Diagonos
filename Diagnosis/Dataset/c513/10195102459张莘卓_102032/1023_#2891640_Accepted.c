#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int strnum(char *s) {
    int i = 0;
    while(s[i] && !isdigit(s[i])) ++i;
    if(s[i] == '\0') return -1;
    else{
        int num = 0;
        while(isdigit(s[i]))
            num = num*10 + s[i++] - '0';
        return num;
    }
}

int cmp(const void* m, const void* n) {
    char *a = *((char**)m), *b = *((char**)n);
    int n1 = strnum(a), n2 = strnum(b);
    if(n1 != n2)  return n1 - n2;
    else  return strcmp(a, b);
}

int main()
{
    char **s = (char**)malloc(100*sizeof(char*));
    char t[31];
    int i = 0;
    while(scanf("%s",t) == 1) {
        s[i] = (char*) malloc(strlen(t)+1);
        strcpy(s[i++], t);
    }
    qsort(s, i, sizeof(char*), cmp);
    for(int k=0; k<i; ++k){
        printf("%s%s",s[k],k<i-1?" ":"\n");
        free(s[k]);
    }
    free(s);
    return 0;
}
