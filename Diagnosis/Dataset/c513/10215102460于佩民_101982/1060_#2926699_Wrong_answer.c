#include <stdio.h>
#include <string.h>

int main(){
    char s[101];
    int i=0,cnt=0,longest=0,num=0;
    gets(s);
    while(s[i]=='0'){
        i++;
    }
    for(;i<=strlen(s);i++){
        while(s[i]=='0'){
            num++;
            i++;
        }
        if((s[i]<'0'&&s[i]!='\0')||s[i]>'9') cnt=0;
        else if(s[i]>='1'&&s[i]<='9'){cnt=cnt+1+num;num=0;}
        else{
            if(cnt>longest) longest=cnt;
            else;
            cnt=0;
        }
    }
    printf("%d",longest);
    return 0;
}