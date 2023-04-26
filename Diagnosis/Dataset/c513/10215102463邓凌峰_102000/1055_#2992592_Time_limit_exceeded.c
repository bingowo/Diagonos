#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 1000000
#define BigNUm 10007

int haveCommon(char *s,char x){
//    if(strlen(s)==1 && s[0]==x) return 0;
    for(int i=0;s[i];i++){
        if(s[i]==x) return 1;
    }
    return 0;
}



int main()
{
    char s[LEN+1]={0};
    scanf("%s",s);
    int cnt=0;
    int start=0,len=0;
    for(int i=0;s[i];i++){
        char tmp[LEN+1]={0};
        for(int j=i;s[j];j++){
            if(haveCommon(tmp,s[j])){
                if(len<strlen(tmp)){
                    start=i;
                    len=strlen(tmp);
                }
                cnt=0;
                break;

            }
            else tmp[cnt++]=s[j];

            if(j==strlen(s)-1){
                if(len<strlen(tmp)){
                    start=i;
                    len=strlen(tmp);
                }
            }
        }
    }

    for(int k=0;k<len;k++){
        printf("%c",s[start+k]);
    }



    return 0;
}
