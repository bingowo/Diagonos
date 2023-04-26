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

void eraser(char *s) {
    int flag = 1;
    char t[102];
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
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[101], copy[102];
        scanf("%s",s);
        int slen = strlen(s), cnt = 0;
        for(int i=0; i<=slen; ++i) {
            for(int k=0; k<i; ++k) copy[k] = s[k];
            for(int k=i+1; k<=slen; ++k) copy[k] = s[k-1];
            copy[slen+1] = '\0';
            for(char c='A'; c<='C'; ++c){
                char temp[102];
                strcpy(temp, copy); temp[i]=c;
                eraser(temp);
                if(slen-strlen(temp)+1 > cnt)
                    cnt = slen - strlen(temp) + 1;
            }
        }
        printf("case #%d:\n%d\n",j,cnt);
    }
    return 0;
}