#include<stdio.h>
#include<string.h>
#include<ctype.h>

void trans(char *s){
    int l=strlen(s);
    int m=l-1;
    while(s[m]>'f')m--;
    long long ans=0;
    for(int i=2;i<=m;i++){
        if(isdigit(s[i]))ans=ans*16+s[i]-'0';
        else ans=ans*16+s[i]-'a'+10;
    }
    printf("%lld",ans\n);
}

int main(){
    char s[100001];
    scanf("%s",s);
    int l=strlen(s),l1=0;
    for(int i=0;i<l-1;i++){
        if(s[i]=='0'&&s[i+1]=='x'){
            strncpy(s0,s+l1,i-l1);
            s0[i-l1]='\0';
            trans(s0);
            l1=i;
        }
    }
    if(l1==0)printf("-1\n");
}