#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//读取到“”，从”后面继续判断
//读取到//直接读下一行
//读取到/*继续读取。后面如果有*/就删掉，没有就全删。

int main(){
    // const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
    // printf("%s", p);   

    char s[1000005] = {0};
    char stemp[10000] = {0};
    while (gets(stemp)!=NULL){
        strcat(s, stemp);
        strcat(s, "\n");
        memset(stemp, 0, 10000);
    }
    int slen = strlen(s);
    for (int i = 0; i < slen; i++){
        if (s[i]=='"'){
            while (i+1<slen && (s[i+1]!='"' || s[i]=='\\')) i++;
        }
        else if (i+1<slen && s[i]=='/' && s[i+1]=='/') {
            //注意还需判断\n是否被包裹在“”内
            for (int j = 1; i+j+1 < slen; j++){
                if (s[i+j]=='"' && s[i+j-1] != '\\'){
                   while (i+j+1<slen && (s[i+j+1]!='"' || s[i+j]=='\\')) j++;
                   j++;
                }
                if (s[i+j] == '\n') {
                    for (int k = 0; i+j+k < slen; k++){
                        s[i+k] = s[i+j+k];
                        s[i+j+k] = '\0';
                    }
                    break;
                }
            }
        }
        else if (i+1<slen && s[i]=='/' && s[i+1]=='*'){
            //注意还需判断*/是否被包裹在“”内
            for (int j = 1; i+j+2 < slen; j++){
                if (s[i+1+j]=='"' && s[i+j]!='\\'){
                   while (i+2+j<slen && (s[i+2+j]!='"' || s[i+1+j]=='\\')) j++;
                   j++;
                }
                if (s[i+1+j] == '*' && i+2+j<slen && s[i+2+j]=='/') {
                    for (int k = 0; i+j+k+3 < slen; k++){
                        s[i+k] = s[i+j+k+3];
                        s[i+k+3] = '\0';
                    }
                    break;
                }
                else if (i+2+j>=slen-1){
                    s[i]=='\0';
                    break;
                }
            }
        }
    }
    printf("%s", s);
    return 0;

}