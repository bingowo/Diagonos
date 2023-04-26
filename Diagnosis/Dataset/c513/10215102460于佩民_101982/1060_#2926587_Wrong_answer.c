#include <stdio.h>
#include <string.h>

int main(){
    char s[101];
    int i=0,cnt=0;
    gets(s);
    while(s[i]==0){
        i++;
    }
    for(;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9') cnt++;
    }
    printf("%d",cnt);
    return 0;
}