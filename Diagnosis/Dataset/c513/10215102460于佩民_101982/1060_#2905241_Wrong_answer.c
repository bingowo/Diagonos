#include <stdio.h>
#include <string.h>

int main(){
    char s[101];
    int longest=0,i,now=0;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='0'){
            if(s[i+1]>='1'&&s[i+1]<='9'&&s[i-1]!='0'){
                now++; continue;
            }}
        else if(s[i]>='1'&&s[i]<='9'){
            if(s[i+1]>='1'&&s[i+1]<='9'){
                now++; continue;
            }
            else if(s[i+1]>='A'&&s[i+1]<='z') now++;
        }
        if(now>longest) {
            longest = now;
            now = 0;
        }
        else now=0;
    }
    printf("%d",longest);
    return 0;
}