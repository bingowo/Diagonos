#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mod 1000000007 
int main(){
    char s[1020];scanf("%s",s);
    long long ans=1;
    if(strlen(s)==2){
        if(s[0]!=s[1]) ans*=4;
    }
    else if(strlen(s)>=3){
        if(s[0]!=s[1]) ans*=2;
        if(s[strlen(s)-1]!=s[strlen(s)-2]) ans*=2;
        for(int i=1;i<strlen(s)-1;i++){
            if(s[i-1]==s[i+1] && s[i]!=s[i-1])ans=ans*2%mod;
            else if(s[i-1]!=s[i+1]){
                if(s[i]!=s[i-1] && s[i]!=s[i+1])ans=ans*3%mod;
                else if(s[i]==s[i-1] || s[i]==s[i+1])ans=ans*2%mod;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
