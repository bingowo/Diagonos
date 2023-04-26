#include<stdio.h>
#include<string.h>
int main(){
    char s[1000];
    char c;
    int i=0;
    while(c=getchar()!=EOF){
         s[i++]=c;
        
    }
     printf("%s",s);
}