#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t=0;
    scanf("%d",&t);
    char s[100000]={0};
    s[0]='0';
    s[1]=0;
    if(t==0) printf("0\n");
    else{
        for(int i=0;i<t-1;i++){
            int len=strlen(s);
            for(int i=0;i<len;i++){
                if(s[i]=='0') s[i+len]='1';
                else s[i+len]='0';
                if(i==len-1) s[i+len+1]=0;
            }
        }
        printf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++){
            char c=0;
            if(s[i]=='0') c='1';
            else c='0';
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}