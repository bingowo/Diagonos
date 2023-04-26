#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char char_comb[17] = "";
void comb(char* s, int depth, int k) {
    if(depth) printf("%s\n",char_comb);
    for(int i=k; s[i]; ++i) {
        char_comb[depth] = s[i];
        char_comb[depth+1] = '\0';
        comb(s, depth+1, i+1);
    }
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
        comb(s, 0, 0);
    }
    return 0;
}
