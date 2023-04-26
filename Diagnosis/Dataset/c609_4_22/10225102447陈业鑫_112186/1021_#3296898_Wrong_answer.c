#include <stdio.h>
#include <string.h>
#define MAXN 110

char dict[30];
char words[MAXN][30];

int cmp(char* str1, char* str2) {
    int i;
    for(i=0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return dict[str1[i]-'A']-dict[str2[i]-'A'];
    }
    return dict[str1[i-1]-'A']-dict[str2[i-1]-'A'];
}

int main() {
    fgets(dict,sizeof(dict),stdin);
    int n=0;
    while (n==0 || words[n-1][0] != '\0') {
        fgets(words[n++],sizeof(words[0]),stdin);
    }
    qsort(words,n,sizeof(char)*30,(int (*)(const void*,const void*))cmp);
    for(int i = 0;i<n-1;++i){
        printf("%s", words[i]);
    }
    printf("%s\n", words[n-1]);
    return 0;
}