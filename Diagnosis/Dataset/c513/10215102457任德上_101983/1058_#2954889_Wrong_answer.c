#include<stdio.h>
#include<string.h>
int main(){
    char s[10000]={0},*s1,c;
    int state=1,i=0;
    while((c=getchar())!=EOF){
        if(c=='\''){
            s[i++]=c;
            while((c=getchar())!=EOF){
                if(c=='\\'){s[i++]=c;c=getchar();s[i++]=c;}
                else if(c=='\''){s[i++]=c;break;}
                else s[i++]=c;
            }
        }
        else if(c=='"'){
            s[i++]=c;
            while((c=getchar())!=EOF){
                if(c=='\\'){s[i++]=c;c=getchar();s[i++]=c;}
                else if(c=='"'){s[i++]=c;break;}
                else s[i++]=c;
            }
        }
        else if(c=='/'&&state==1)state=2;
        else if(c=='/'&&state==2)state=3;
        else if(c=='\n'&&state==3){
            s[i++]=c;
            state=1;
        }
        else if(c=='*'&&state==2)state=4;
        else if(c=='*'&&state==4)state=5;
        else if(c=='/'&&state==5)state=1;
        else if(state==1&&c!='/')s[i++]=c;
    }
    printf("%s",s);
    return 0;
}