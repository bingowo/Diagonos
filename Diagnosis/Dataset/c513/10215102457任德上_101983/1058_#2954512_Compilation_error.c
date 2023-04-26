#include<stdio.h>
#include<string.h>
int main(){
    char s[10000]={0},*s1,c;
    int state=1,i=0;
    while((c=getchar())!=EOF){
        if(c=='/'&&state==1){
            state=2;
            s[i++]=c;
        }   
        else if(c=='/'&&state==2)state=3
        else if(c=='\n'&&state==3)state=1;
        else if(c=='*'&&state==2)state=4;
        else if(c=='*'&&state==4)state=5;
        else if(c!='/'&&state==5)state=4;
        else if(c=='/'&&state==5)state=1;
        else s[i++]=c;
    }
    printf("%s",s);
    return 0;
}