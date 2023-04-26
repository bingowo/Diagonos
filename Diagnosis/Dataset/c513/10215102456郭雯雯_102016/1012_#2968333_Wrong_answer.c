#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[500];
    scanf("%s",s);
    int l=strlen(s),a,b;
    if(s[l-1]=='i'){
        for(int i=l-2;i>=0&&isdigit(s[i]);i--);
    }
}