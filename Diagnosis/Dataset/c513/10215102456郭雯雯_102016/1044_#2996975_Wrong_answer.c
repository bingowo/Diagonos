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
    printf("%lld ",ans);
}

int main(){
    char s[100001],s0[100001];
    scanf("%s",s);
    int l=strlen(s),n=0;
    for(int i=0;i<l-1;i++){
        if(s[i]=='0'&&s[i+1]=='x'){
            int m=i+2;
            while(isdigit(s[m])||(s[m]>='a'&&s[m]<='f'))m++;
            strncpy(s0,s+i,m-i);
            s0[m-i]='\0';
            trans(s0);
            i=m-1;n++;
        }
    }
    if(n==0)printf("-1\n");
}