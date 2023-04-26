#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000

int main()
{
    char s[N+1];
    for(int i=0;i<N+1;i++){s[i]='\0';}
    scanf("%s",&s);
    int start=0,ans=0,isout=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='0' && s[i+1]=='x'){
            if(start){
                printf("%d ",ans);isout=1;
                ans=0;i++;
                continue;
            }
            else start=1;i+=2;
        }
        if(s[i]>'f'){
            if(start){
                printf("%d ",ans);
                isout=1;
                ans=0;
            }
            start=0;
        }
        if(start){
            if('0'<=s[i] && s[i]<='9'){
                if(s[i]=='0' && s[i+1]=='x' && s[i+2]<='x'){
                    if(ans!=0){
                        printf("%d ",ans);
                        isout=1;ans=0;
                    }
                    ans=0;i++;
                    continue;
                }
                ans=ans*16+s[i]-'0';
            }
            if('a'<=s[i] && s[i]<='f'){
                ans=ans*16+s[i]-'a'+10;
            }
        }
        if(i>=strlen(s)-1){
            if(start){
                if(ans>0){
                    printf("%d ",ans);
                    isout=1;ans=0;
                }
            }
            else if(isout==0) printf("-1");
        }
    }

    return 0;
}
