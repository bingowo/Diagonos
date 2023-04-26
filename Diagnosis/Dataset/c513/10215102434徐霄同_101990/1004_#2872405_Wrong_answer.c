#include <stdio.h>
#include <ctype.h>
#include <string.h>
int atoi(char s[])
{
    int v,i,s1;
    i=0;
    s1=(s[i]=='-')?-1:1;
    if (s[i]=='-')
        i=1;
    for(v=0;isdigit(s[i]);i++)
        v=10*v+(s[i]-'0');
    v=s1*v;
    return v;
}
double atof(char s[])
{
    double v,p;
    int i,s1;
    i=0;
    s1=(s[i]=='-')?-1:1;
    if (s[i]=='-')
        i=1;
    for(v=0.0;isdigit(s[i]);i++)
        v=10.0*v+(s[i]-'0');
    if (s[i]=='.')
        i++;
    for(p=1.0;isdigit(s[i]);i++){
        v=10.0*v+(s[i]-'0');
        p*=10.0;
    }
    v=s1*v/p;
    return v;
}

int main() {
    char s[100];
    int a[64];
    int i,l,xi,t;
    double xd;
    while(scanf("%s",s)!=EOF){
        l=strlen(s);
        for(i=0;s[i]!='.'&&i<l;i++)
            ;
        if(i==l){
            t=0;
            xi=atoi(s);
        }
        else{
            t=1;
            xd=atof(s);
        }
    }
    return 0;
}
