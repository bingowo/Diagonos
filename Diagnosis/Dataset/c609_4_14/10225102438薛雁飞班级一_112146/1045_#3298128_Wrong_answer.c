#include <stdio.h>
#include <stdlib.h>

int main()
{
    int state=0; 
    char c; 
    while((c=getchar())!=EOF){ 
    if(state==0&&c=='/') 
        state=1; 
    else if(state==1&&c=='*') 
        state=2; 
    else if(state==1&&c=='/') 
        state=3; 
    else if(state==1){ 
        printf("%c",c);
        state=0; 
    }else if(state==2&&c!='*') 
        state=2; 
    else if(state==2&&c=='*') 
        state=4; 
    else if(state==4&&c=='*') 
        state=4; 
    else if(state==4&&c=='/') 
        state=0; 
    else if(state==4) 
        state=2; 
    else if(state==3&&c=='\n') 
        state=0; 
    else if(state==0&&c=='\'') 
        state=5; 
    else if(state==5&&c=='\\') 
        state=6; 
    else if(state==6) 
        state=5; 
    else if(state==5&&c=='\'') 
        state=0;
    else if(state==0&&c=='\"') 
        state=7; 
    else if(state==7&&c=='\\') 
        state=8; 
    else if(state==7&&c=='\"') 
        state=0; 
    else if(state==8) 
        state=7; 
    if((state==0&&c!='/')||state==5||state==6||state==7||state==8) 
        printf("%c",c);
    } 
return 0; 
}