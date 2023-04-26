#include <stdio.h>
#include <string.h>

int main(){
    char s[51];
    int i,length=1,now=1;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='|'){
            if(s[i+1]=='-') now++;
            else if(now>length){
                length=now;
                now=1;
            }
            else if(now<=length) now=1;
        }
        else if(s[i]=='-'){
            if(s[i+1]=='|') now++;
            else if(now>length){
                length=now;
                now=1;
            }
            else if(now<=length) now=1;
        }
    }
    printf("%d",length);
    return 0;
}