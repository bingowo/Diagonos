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
                else {
                    s[j]=s[j]+jinwei;
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
