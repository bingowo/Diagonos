#include<stdio.h>
#include<string.h>

int turn(char c){
    int t;
    if(c=='I')t=1;
    else if(c=='V')t=5;
    else if(c=='X')t=10;
    else if(c=='L')t=50;
    else if(c=='C')t=100;
    else if(c=='D')t=500;
    else if(c=='M')t=1000;
    return t;
}
int main(){
    char s[55];
    scanf("%s",s);
    long long ans=0,pow=1,num[55]={0};
    int l=strlen(s),n=0;
    for(int i=0;i<l;i++){
        switch(s[i]){
            case '(':pow*=1000;break;
            case ')':pow/=1000;break;
            default:num[n++]=turn(s[i])*pow;break;
        }
    }
    for(int i=0;i<n-1;i++){
        if(num[i]<num[i+1])ans-=num[i];
        else ans+=num[i];
    }
    ans+=num[n-1];
    printf("%lld\n",ans);
}