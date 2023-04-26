#include<stdio.h>
#include<ctype.h>
int main(){
    char c,s[2051]={0},*s1,*s2;
    s1=s+1025;
    *s1=getchar();
    s2=s1;
    while((c=getchar())!='\n'){
        c=toupper(c);
        if(c>=*s1){
            s1--;
            *s1=c;
        }
        else{
            s2++;Programming

            *s2=c;

        }
    }
    printf("%s",s1);
    return 0;





}
