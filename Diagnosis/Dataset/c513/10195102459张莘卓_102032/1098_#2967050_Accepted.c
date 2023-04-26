#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char color[5] = "RBYG";
    for(int t=0; t<T; ++t) {
        int cnt[26] = {0};
        char s[101], c = 0;
        scanf("%s",s);
        for(int j=0; j<4; ++j){
            if(strchr(s, color[j]) == NULL) {
                c = color[j];
                continue;
            }
            char cur = color[j];
            int k = (int)(strchr(s, color[j]) - s);
            for(int i=1; k-4*i>=0; ++i)
                if(s[k-4*i] == '!'){
                    ++cnt[cur-'A'];
                    s[k-4*i] = cur;
                }
            for(int i=1; k+4*i<strlen(s); ++i)
                if(s[k+4*i] == '!') {
                    ++cnt[cur-'A'];
                    s[k+4*i] = cur;
                }
        }
        if(c != '\0') {
            for(int i=0; i<strlen(s); ++i)
                if(s[i] == '!') ++cnt[c-'A'];
        }
        printf("case #%d:\n",t);
        for(int i=0; i<4; ++i)
            printf("%d%s",cnt[color[i]-'A'],i<3?" ":"\n");
    }
    return 0;
}
