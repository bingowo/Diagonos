#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int judge(char s){
    int i;
    for(i=1;i<strlen(s);i++){
        if(s[i]=s[i-1]){
            return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    int i;
    char s[1000];
    for(i=0;i<t;i++){
        scanf("%s",s);
        printf("%d",judge(s));
    }
}