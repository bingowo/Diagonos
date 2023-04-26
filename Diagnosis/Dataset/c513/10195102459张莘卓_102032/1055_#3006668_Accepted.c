#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s = (char*) malloc(1000001*sizeof(char));
    scanf("%s",s);
    int r = 0, len=0, begin=0;
    int flag[127] = {0};
    for(int i=0; s[i]; ++i) {
        flag[s[i]] = 1;
        if(r <= i) r = i + 1;
        while(s[r] && flag[s[r]]==0)
            flag[s[r++]] = 1;
        if(r-i > len) {
            len = r - i;
            begin = i;
        }
        flag[s[i]] = 0;
    }
    for(int i=begin; i<begin+len; ++i)
        printf("%c",s[i]);
    printf("\n");
    free(s);
}
