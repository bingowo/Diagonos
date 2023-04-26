#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    char s[100];
    int i;
    int len=1;
    int max=1;
    scanf("%s",s);
    for(i=1;i<strlen(s);i++){
        if(s[i]!=s[i-1]){
            len++;
            if(len>max){
                max=len;
            }
        }else{
            len=1;
        }
    }
    printf("%d",max);
}