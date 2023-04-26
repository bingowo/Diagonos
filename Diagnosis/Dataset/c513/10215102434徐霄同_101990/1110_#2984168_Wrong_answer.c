#include <stdio.h>
#include <string.h>
#include <ctype.h>
int f(char s[],int x,int l,char c)
{
    int i,n,t;
    i=x;
    if(s[i]==c||(s[i]=='+'&&s[i+1]==c))
        return 1;
    else if(s[i]=='-'&&s[i+1]==c)
        return -1;
    if(s[x]=='-'){
        t=-1;
        i++;
    }
    else{
        t=1;
        if(s[x]=='+')
            i++;
    }
    n=0;
    while(i<l&&isdigit(s[i])){
        n=n*10+s[i]-'0';
        i++;
    }
    return n*t;
}
int main()
{
    char s[81];
    char x;
    int i,l,ld,a,b,c,d,n;
    double ans;
    scanf("%s",s);
    l=strlen(s);
    i=0;
    while(!isalpha(s[i]))
        i++;
    x=s[i];
    ld=0;
    while(s[ld]!='=')
        ld++;
    a=0;b=0;c=0;d=0;
    i=0;
    while(s[i]!='='){
        n=f(s,i,ld,x);
        i++;
        while(isdigit(s[i]))
            i++;
        if(s[i]==x){
            a=a+n;
            i++;
        }
        else
            b=b+n;
    }
    i++;
    while(i<l){
        n=f(s,i,l,x);
        i++;
        while(isdigit(s[i]))
            i++;
        if(s[i]==x){
            c=c+n;
            i++;
        }
        else
            d=d+n;
    }
    ans=(double)(d-b)/(double)(a-c);
    printf("%c=%.3f\n",x,ans);
    return 0;
}
