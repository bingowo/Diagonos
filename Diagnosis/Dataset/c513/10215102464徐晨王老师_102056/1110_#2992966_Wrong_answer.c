#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[90];
    gets(s);
    int x=0;
    char s1[90];
    if(s[0]=='-'||s[0]=='+')x=x;
    else {s1[0]='+';x++;}
    int i;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='=')break;
        else{
            s1[x]=s[i];
            x++;
        }
    }
    i=i+1;
    char s2[90];
    int y=0;
    if(s[i]=='-'||s[i]=='+')y=y;
    else {s2[0]='+';y++;}
    for(;i<strlen(s);i++){
        s2[y]=s[i];
        y++;
    }
    printf("%s %s",s1,s2);
}
