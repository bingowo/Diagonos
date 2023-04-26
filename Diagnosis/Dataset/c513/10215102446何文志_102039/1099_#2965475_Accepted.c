#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[40][10] = {
    ".-",         "-...",        "-.-.",      "-..",
    ".",          "..-.",        "--.",       "....",
    "..",         ".---",        "-.-",       ".-..",
    "--",         "-.",          "---",       ".--.",
    "--.-",       ".-.",         "...",       "-",
    "..-",        "...-",        ".--",       "-..-",
    "-.--",       "--..",
    "-----",      ".----",       "..---",     "...--",
    "....-",      ".....",       "-....",     "--...",
    "---..",      "----."
};

char MorseToAlnum(char* s){
    if(strcmp(s,"///")==0){
        return ' ';
    }
    if(strcmp(s,"/////")==0){
        return '.';
    }
    for(int i = 0;i<26;i++){
        if(strcmp(s,table[i])==0){
            return 'A'+i;
        }
    }
    for(int i = 26;i<36;i++){
        if(strcmp(s,table[i])==0){
            return '0'+i-26;
        }
    }
    return 0;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        char s[1100];memset(s,0,1100*sizeof(char));
        scanf("%s",s);
        char split[1000][10];memset(split,0,1000*10*sizeof(char));
        char res[1100];memset(res,0,1100*sizeof(char));
        int cnt = 0,slen = strlen(s);
        int j = 0;
        while(j<slen){
            int cur = 0;
            if((s[j]=='.')||(s[j]=='-')){
                while((s[j]=='.')||(s[j]=='-')){
                    split[cnt][cur] = s[j];
                    cur++;j++;
                }
                cnt++;
                continue;
            }
            else if(s[j]=='/'){
                while(s[j]=='/'){
                    split[cnt][cur] = s[j];
                    cur++;j++;
                }
                cnt++;
                continue;
            }
        }
        int resCnt = 0;
        for(int j = 0;j<cnt;j++){
            if(strcmp(split[j],"/")!=0){
                res[resCnt] = MorseToAlnum(split[j]);
                //printf("res = %c\n",res[resCnt]);
                resCnt++;
            }
            //printf("%d: %s\n",j,split[j]);

        }
        printf("case #%d:\n%s\n",i,res);
    }
    return 0;
}
