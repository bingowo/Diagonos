#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eraser(char *s, int len) {
    char t[110];
    int flag = 1;
    do{
        int k = 0;
        for(int i=0; i<len; ++i){
            if(i==0 && s[i]!=s[i+1]) t[k++] = s[i];
            else if(i==len-1 && i-1>=0 && s[i]!=s[i-1])
                t[k++] = s[i];
            else if(s[i]!=s[i+1] && s[i]!=s[i-1]) t[k++] = s[i];
        }
        t[k] = '\0';
        len = k;
        flag = strcmp(s, t);
        strcpy(s, t);
    }while(flag);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[101];
        scanf("%s",s);
        int cnt = 0;
        for(int i=0; i<=strlen(s); ++i) {
            char t[102];
            for(int k=0; k<i; ++k) t[k] = s[k];
            for(int k=i; k<strlen(s); ++k) t[k+1] = s[k];
            t[strlen(s)+1] = '\0';
            for(char c='A'; c<='C'; ++c) {
                char copy[110]; strcpy(copy, t);
                copy[i] = c;
                eraser(copy, strlen(copy));
                if(strlen(s)+1-strlen(copy) > cnt)
                    cnt = strlen(s)+1-strlen(copy);
            }
        }
        printf("case #%d:\n%d\n",j,cnt);
    }
    return 0;
}
