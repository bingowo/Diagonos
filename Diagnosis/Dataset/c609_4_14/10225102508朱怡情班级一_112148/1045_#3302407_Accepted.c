#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c;
    int state=0;
    while((c=getchar())!=EOF){
        if(state==0){
            if(c=='/')state=1;
            else if(c=='\'')state=5;
            else if(c=='\"')state=7;
        }
        else if(state==1){
            if(c=='/')state=4;
            else if(c=='*')state=2;
            else{
                state=0;
                printf("/");
            }
        }
        else if(state==2&&c=='*')state=3;
        else if(state==3){
            if(c=='/')state=0;
            else if(c!='*')state=2;
        }
        else if(state==4&&c=='\n')state=0;
        else if(state==5){
            if(c=='\'')state=0;
            else if(c=='\\')state=6;
        }
        else if(state==6)state=5;
        else if(state==7){
            if(c=='\"')state=0;
            else if(c=='\\')state=8;
        }
        else if(state==8)state=7;
        if((state==0&&c!='/')||state==5||state==6||state==7||state==8)printf("%c",c);
    }
    return 0;
}