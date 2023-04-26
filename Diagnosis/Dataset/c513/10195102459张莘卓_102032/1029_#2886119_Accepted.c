#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a, const void* b) {
    return *((char*)a) - *((char*)b);
}
 
int main()
{
    int T;
    scanf("%d",&T); getchar();
    for(int j=0; j<T; ++j) {
        char s[201], alpha[200];
        gets(s);
        int k = 0;
        for(int i=0; s[i]; ++i) {
            if(isalpha(s[i]))
                alpha[k++] = s[i];
        }
        qsort(alpha, k, sizeof(char), cmp);
        printf("case #%d:\n",j);
        k = 0;
        for(int i=0; s[i]; ++i) {
            if(isalpha(s[i]))  printf("%c",alpha[k++]);
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
