#include<stdio.h>
#include<string.h>

int main(){
    char s[85]={0};
    while(scanf("%s", s)!=EOF){
        int slen=strlen(s),base=80,high=80,low=80;
        char res[165][85]={};//首列装最远下标
        res[80][0]='1',res[80][1]=s[0];
        for (int i=1; i<slen; i++){
            if (s[i]>s[i-1]) {res[++base][i+1]=s[i];res[base][0]=i+1+'0';high=high<base?base:high;}
            else if(s[i]<s[i-1]){res[--base][i+1]=s[i];res[base][0]=i+1+'0';low=low>base?base:low;}
            else {res[base][i+1]=s[i];res[base][0]=i+1+'0';}
        }
        for (int i=high; i>=low; i--){
            for (int j=1; j<=res[i][0]-'0'; j++) {
                if (res[i][j]=='\0') printf(" ");
                else printf("%c", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}