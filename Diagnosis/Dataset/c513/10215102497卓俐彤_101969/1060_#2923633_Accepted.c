#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[101];
    scanf("%s",s);
    int len=0,maxlen=0;
    int flag=0;
    for(int i=0;i<strlen(s);i++){
        if(isdigit(s[i])){
            if(!flag&&s[i]!='0'){
                flag=1;len=1;
            }
            else if(flag)len++;
        }else{
            flag=0;maxlen=maxlen>len?maxlen:len;
        }
    }
    maxlen=maxlen>len?maxlen:len;
    printf("%d\n",maxlen);
    return 0;
}
