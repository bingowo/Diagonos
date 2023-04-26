#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eraser(char *s, char* t) {
    int flag = 1;
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
        char s[101], t[101], copy[102];
        scanf("%s",s);
        int slen = strlen(s);
        int cnt = 0;
        for(int i=0; i<=slen; ++i) {
            for(int k=0; k<i; ++k) copy[k] = s[k];
            for(int k=i+1; k<=slen; ++k) copy[k] = s[k-1];
            copy[slen+1] = '\0';
            for(char c='A'; c<='C'; ++c){
                char temp[102];
                strcpy(temp, copy); temp[i]=c;
                eraser(temp, t);
                if(slen-strlen(temp)+1 > cnt)
                    cnt = slen - strlen(temp) + 1;
            }
        }
        printf("case #%d:\n%d\n",j,cnt);
    }
    return 0;
}