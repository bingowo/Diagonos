#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[501];
        scanf("%s",s);
        printf("case #%d:\n",j);
        for(int i=0; s[i]; ++i) {
            char c = s[i];
            int cnt = 1;
            while(s[i+1] == c && cnt < 255){
                ++i;
                ++cnt;
            }
            printf("%d%c",cnt,c);
        }
        printf("\n");
    }
    return 0;
}
