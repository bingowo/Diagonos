#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int block(char *s, int len) {
    if(len == 0) return 0;
    int max = 1;
    for(int i=1; i<len-1; ++i) {
        int k = 1;
        while(i-k>=0 && i+k<len && s[i-k]==s[i+k])
            ++k;
        --k;
        if(2*k+1 > max) max = 2*k + 1;
    }
    return max;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[101], t[101];
        scanf("%s",s);
        int flag = 1;
        int slen = strlen(s);
        do{
            int k = 0;
            for(int i=0; s[i]; ++i){
                if(i==0 && s[i]!=s[i+1])
                    t[k++] = s[i];
                else if(!s[i+1] && s[i-1]!=s[i])
                    t[k++] = s[i];
                else if(s[i]!=s[i-1] && s[i]!=s[i+1])
                    t[k++] = s[i];
            }
            t[k] = '\0';
            flag = strcmp(s, t);
            strcpy(s, t);
        }while(flag);
        int cnt = slen-strlen(t)+block(t, strlen(t))+1;
        printf("case #%d:\n%d\n",j,cnt);
    }
    return 0;
}
