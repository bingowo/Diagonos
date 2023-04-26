#include<stdio.h>
#include<string.h>
#define N 1001
#define MOD 1000000007
int main(){
    char s[N];
    scanf("%s",s);
    long int ans=1;
    int n=strlen(s);
    if(n==1){printf("1");return 0;}
    for(int i=0;i<n;i++){
        if(i==0){
            if(s[i]==s[i+1])continue;
            else ans=ans*2%MOD;
        }
        else if(i==n-1){
            if(s[i]==s[i-1])continue;
            else ans=ans*2%MOD;
        }
        else{
            if(s[i]==s[i-1]&&s[i]==s[i+1])continue;
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])ans=ans*3%MOD;
            else ans=ans*2%MOD;
        }
    }
    printf("%ld",ans%MOD);
}