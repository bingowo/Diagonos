#include<stdio.h>
#include<ctype.h>
int main(){
    char s[101],*s1;
    scanf("%s",s);
    s1=s;
    int len=0,max=0,begin=0;
    while(*s1){
        if(isdigit(*s1)&&*s1!='0')begin=1;
        if(isdigit(*s1)&&begin==1)len++;
        else{
            if(len>max)max=len;
            len=0;
            begin=0;
        }
        s1++;
    }
    printf("%d",max);
    
    return 0;
}