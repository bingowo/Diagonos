#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[210];
    scanf("%s",&s);
    int len=strlen(s);
    for(int i=0;i<len-1;i++){
        if(s[i]<s[i+1]){
            len++;
            for(int t=len-2;t>=i;t--)
                s[t+1]=s[t];
            i++;
        }
        else if(s[i]==s[i+1]){
            int flag=1;
            for(int t=i+1;t<len-1;t++){
                if(s[t]>s[t+1]) {
                    flag=0;
                    break;
                }
            }
            if(flag){
                len++;
                for(int t=len-2;t>=i;t--)
                    s[t+1]=s[t];
                i++;
            }
        }
    }
    for(int t=0;t<len;t++) printf("%c",s[t]);
    printf("\n");
    return 0;
}