#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char p[1000];
    int len=0;
    while((p[len]=getchar())!=EOF){
        len=len+1;
    }
    len=len+1;
    //printf("%d",len);
    int flag1=1;
    int flag2=1;
    for(int i=0;i<len;i++){
        if(p[i]=='/'&&p[i+1]=='/')flag1=0;
        if(p[i]=='\n')flag1=1;
        if(p[i]=='/'&&p[i+1]=='*')flag2=0;
        if(p[i-2]=='*'&&p[i-1]=='/')flag2=1;

       if(flag1&&flag2)printf("%c",p[i]);
    }
    //printf("%c",p[len-1]);
    return 0;
}
