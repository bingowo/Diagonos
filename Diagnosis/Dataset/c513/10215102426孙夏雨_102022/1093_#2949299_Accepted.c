#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int len=strlen(s);
    int jinwei=1,all=0;
    for(int i=len-1;i>=0;i--){
        if(jinwei==1){
            if(s[i]=='8') s[i]='0';
            else if(s[i]=='9'){
                s[i]='0';
                jinwei=1;
            }
            else {
                s[i]=s[i]+jinwei;
                jinwei=0;
            }
        }
        all+=(s[i]-'0');
    }
    all+=jinwei;
    char c='0';
    if (jinwei==1) c='1';
    jinwei=1;
    if(all%9==0){
        for(int j=len-1;j>=0;j--){
            if(jinwei==1){
                if(s[j]=='8') s[j]='0';
                else if(s[j]=='9'){
                    s[j]='0';
                    jinwei=1;
                }
                else {
                    s[j]=s[j]+jinwei;
                    jinwei=0;
                }
            }
        }
        if(jinwei==1) c++;
    }
    int weizhi=-1;
    for(int k=0;k<len;k++){
        if(s[k]=='9') {weizhi=k;s[k]='0';}
        if(weizhi>=0) s[k]='0';
    }
    if(weizhi!=-1){
        jinwei=1;
        for(int w=weizhi-1;w>=0;w--){
            if(jinwei==1) {
                if(s[w]=='8') s[w]='0';
                else {
                    s[w]=s[w]+jinwei;
                    jinwei=0;
                }
            }
        }
        if(jinwei==1) c++;
    }
    if(c>'0') printf("%c",c);
    printf("%s\n",s);
    return 0;
}
