#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c_comb[17] = "";
void comb(char* s, char* char_comb) {
    if(*s == '\0') return;
    sprintf(char_comb, "%s%c",char_comb,s[0]);
    printf("%s\n",char_comb);
    comb(s+1, char_comb);
    char_comb[strlen(char_comb)-1] = '\0';
    comb(s+1, char_comb);
}

int cmp(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

int main()
{
    int T;  scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int cnt[127] = {0};
        char t[17], s[17];
        scanf("%s",t);
        int k = 0;
        for(int i=0; t[i]; ++i) {
            if(cnt[t[i]] == 0) {
                ++cnt[t[i]];
                s[k++] = t[i];
            }
        }
        s[k] = '\0';
        qsort(s, k, sizeof(char), cmp);
        printf("case #%d:\n",j);
        comb(s, c_comb);
    }
    return 0;
}
