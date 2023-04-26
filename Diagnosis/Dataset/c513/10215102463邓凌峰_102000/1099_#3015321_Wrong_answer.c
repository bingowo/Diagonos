#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 1010
#define BigNUm 10007
#define N 100000

char alpha[26][10]={
    ".-",   "-...", "-.-.", "-..",
    ".",    "..-.", "--.",  "....",
    "..",   ".---", "-.-",  ".-..",
    "--",   "-.",   "---",  ".--",
    "--.-", ".-.",  "...",  "-",
    "..-",  "...-", ".--",  "-..-",
    "-.--", "--.."
};

char digit[10][10]={
    "-----",    ".----",    "..---",    "...--",
    "....-",    ".....",    "-....",    "--...",
    "---..",    "----."
};




int main()
{

    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        char codes[LEN]={0};
        scanf("%s",codes);
        int len=strlen(codes);
        char ans[500]={0};
        int cnt=0;
        int idx=0;
        while(1){
            if(idx>=len)break;
            char tmp[10]={0};
            int tmpCnt=0;
            while(codes[idx]!='/' && idx<len){
                tmp[tmpCnt++]=codes[idx++];
            }
            if(strlen(tmp)==5){
                for(int k=0;k<10;k++){
                    if(strcmp(tmp,digit[k])==0){
                        ans[cnt++]='0'+k;
                        break;
                    }
                }
            }
            else{
                for(int k=0;k<26;k++){
                    if(strcmp(tmp,alpha[k])==0){
                        ans[cnt++]='A'+k;
                        break;
                    }
                }
            }
            if(idx>=len)break;
            else if(codes[idx+1]!='/'){
                idx++;
            }
            else if(codes[idx+3]!='/'){
                idx+=3;
                ans[cnt++]=' ';
            }
            else if(codes[idx+5]!='/'){
                idx+=5;
                ans[cnt++]='.';
            }





        }
        printf("case #%d:\n",I);
        printf("%s\n",ans);
    }


    return 0;
}


