#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char *s = (char*)malloc(1000000+1);
    scanf("%s",s);
    int k = 1, mlen = 1, l=0, r=1;
    int cnt[127] = {0};
    for(int i=0; s[k]; ++i) {
        if(i) cnt[s[i-1]] = 0;
        cnt[s[i]] = 1;
        if(k == i) ++k;
        while(s[k] && cnt[s[k]]==0){
            cnt[s[k++]] = 1;
        }
        if(k-i > mlen){
            mlen = k - i;
            l = i; r = k;
        }
    }
    while(l < r) printf("%c",s[l++]);
    printf("\n");
    return 0;
}
