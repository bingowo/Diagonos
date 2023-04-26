#include<stdio.h>
#include<string.h>

int main(){
    char s[1001];
    scanf("%s",s);
    long long n=1;
    int l=strlen(s);
    if(s[0]!=s[1])n*=2;
    else n*=1;
    if(s[l-2]!=s[1-1])n*=2;
    else n*=1;
    for(int i=1;i<l-1;i++){
        if(s[i]!=s[i-1]&&s[i]!=s[i+1])n*=3;
        else if(s[i]!=s[i-1]&&s[i]==s[i+1])n*=2;
        else if(s[i]==s[i-1]&&s[i]!=s[i+1])n*=2;
        else if(s[i]==s[i-1]&&s[i]==s[i+1])n*=1;
    }
    if(l==1)n=1;
    printf("%lld",n);
}