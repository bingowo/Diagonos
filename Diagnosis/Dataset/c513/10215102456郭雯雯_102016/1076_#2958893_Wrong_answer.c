#include<stdio.h>
#include<string.h>

int main(){
    char s[6]="123456";
    s[3]='\0';
    int l=strlen(s);
    printf("%d",l);
}