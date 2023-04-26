#include <stdio.h>
#include <string.h>

int main(){
    char s[101];
    int i=0,cnt=0,longest=0,flag=0;
    gets(s);
    while(s[i]=='0'){
        i++;
    }
    for(;i<=strlen(s);i++){
        if((s[i-1]<'0'||s[i-1]>'9')&&s[i]=='0') {
            flag=1;continue;}
        else if(flag==1&&s[i]=='0') continue;
        else if(s[i]>='0'&&s[i]<='9') {cnt++; flag=0;}
        else{
            if(cnt>longest) {longest=cnt;}
            else;
            cnt=0;
        }
    }
    printf("%d",longest);
    return 0;
}