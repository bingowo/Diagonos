#include <stdio.h>
#include <string.h>
#include <ctype.h>
long long f(char s[],int x)
{
    int i,l;
    long long n,f;
    l=strlen(s);
    i=x;
    f=1;
    if(s[i]=='-'){
        f=-1;
        i++;
    }
    else if(s[i]=='+')
        i++;
    if(s[i]=='i')
        return f;
    n=0;
    while(i<l&&isdigit(s[i])){
        n=n*10+s[i]-'0';
        i++;
    }
    return n*f;
}
int main()
{
    char s[50];
    int i,l;
    long long a,b;
    scanf("%s",s);
    l=strlen(s);
    if(s[l-1]!='i'){
        b=0;
        a=f(s,0);
    }
    else{
        i=0;
        if(s[i]=='+'||s[i]=='-')
            i++;
        while(isdigit(s[i]))
            i++;
        if(s[i]=='i'){
            a=0;
            b=f(s,0);
        }
        else{
            a=f(s,0);
            b=f(s,i);
        }
    }
    printf("%lld %lld",a,b);
    return 0;
}