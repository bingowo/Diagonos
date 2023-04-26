#include<stdio.h>
#include<string.h>
int main(){
    char s[1000];
    while(char c=getchar()!=EOF){
         gets(s);
         printf("%s",s);
    }
   
}