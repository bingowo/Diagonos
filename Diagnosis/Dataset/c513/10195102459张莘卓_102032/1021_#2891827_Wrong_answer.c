#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char alpha[27];
int findalpha(char a, char b) {
    for(int i=0; i<27; ++i){
        if(alpha[i] == a) return -1;
        if(alpha[i] == b) return 1;
    }
    return -1;
}

int cmp(const void* m, const void* n) {
    char *a = *((char**)m), *b = *((char**)n);
    int i = 0;
    while(toupper(a[i]) == toupper(b[i])) ++i;
    return findalpha(toupper(a[i]), toupper(b[i]));
}

int main()
{
    while(scanf("%s",alpha) == 1) {
        char **s = (char**)malloc(100*sizeof(char*));
        int i = 0; char t[101];
        do{
            scanf("%s",t);
            s[i] = (char*)malloc(strlen(t)+1);
            strcpy(s[i++], t);
        }while(getchar() != '\n');
        qsort(s, i, sizeof(char*), cmp);
        for(int k=0; k<i; ++k){
            printf("%s%s",s[k],k<i-1?" ":"\n");
            free(s[k]);
        }
        free(s);
    }
    return 0;
}
