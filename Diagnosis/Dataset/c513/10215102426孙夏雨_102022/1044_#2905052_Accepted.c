#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s0[100001];
    scanf("%s",s0);
    int len=strlen(s0);
    unsigned int ans=0;
    int hefa=-1,i=0,jixu=0;
    while(i<len){
        if((s0[i]=='0')&&(s0[i+1]=='x')&&jixu==0){
            if((i+2)<len) i+=2;
            else break;
            if(isdigit(s0[i])){
                hefa=1;
                jixu=1;
                ans=ans*16+s0[i]-'0';
                i++;
            }
            else if((s0[i]-'a')<=5){
                hefa=1;
                jixu=1;
                ans=ans*16+s0[i]-'a'+10;
                i++;
            }
            else if(isalpha(s0[i])) i++;
        }
        else if(jixu==0) i++;
        else if(isdigit(s0[i])&&jixu==1) {
            ans=ans*16+s0[i]-'0';
            i++;
        }
        else if(((s0[i]-'a')<=5)&&jixu==1){
            ans=ans*16+s0[i]-'a'+10;
            i++;
        }
        else if(isalpha(s0[i])){
            if(jixu==1) printf("%u ",ans);
            ans=0;
            jixu=0;
            i++;
        }
        if(i==len){
            if(jixu==1) printf("%u",ans);
        }
    }
    if(hefa<0) printf("-1");
    return 0;
}
