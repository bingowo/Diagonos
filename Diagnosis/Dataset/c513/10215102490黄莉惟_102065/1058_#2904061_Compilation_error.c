#include<stdio.h>
#include<string.h>
int main(){
    char s[1000];
    while(s=getchar()!=EOF){
         gets(s);
         printf("%s",s);
    }
   
}
