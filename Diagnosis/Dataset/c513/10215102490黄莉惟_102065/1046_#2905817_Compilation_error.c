#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    int t,word;
    int i;
    char s[1000];
    char s1[1000];
    s1="for";
    scanf("%d",&t);
    char c = getchar();	
    for(i=0;i<t;i++){
        gets(s);
        if(s1=="for"){
            printf("1");
        }else{
            printf("0");
        }
        
    }
}