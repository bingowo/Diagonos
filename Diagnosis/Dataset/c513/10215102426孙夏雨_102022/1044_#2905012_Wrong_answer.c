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
        if((s0[i]=='0')&&(s0[i+1]=='x')){
            i+=2;
            if(isdigit(s0[i])&&s0[i]!='0'){
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
            else if(isalpha(s0[i])){
                i++;
                if(ans>0) printf("%u ",ans);
            }
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
            if(ans>0) {
                printf("%u ",ans);
                ans=0;
            }
            jixu=0;
            i++;
        }
        if(i==len){
            if(ans>0) printf("%u",ans);
        }
    }
    if(hefa<0) printf("-1");
    return 0;
}
