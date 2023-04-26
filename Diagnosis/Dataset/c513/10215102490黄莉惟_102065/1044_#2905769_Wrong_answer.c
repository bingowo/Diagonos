#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    char s[10000];
    char s1[10000];
    scanf("%s",s);
    int i=0;
    int num=0;
    int res=0;
    int temp=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='x'){
            res++;
            if(s[i-1]!='0'){
                temp++;
            }
        }
    }
    if(res==0||temp!=0){
        printf("-1");
    }else{
        for(i=0;i<strlen(s);i++){
            if(s[i]<='9'&&s[i]>='0'){
                s1[num]=s[i];
            }
        }
    }
    
}