#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[81],c;
    scanf("%s",s);
    int len=strlen(s),i=0,xishu=0,chang=0,xi=0,sig=1;
    double ans;
    for(;s[i]!='=';i++){
        if(isdigit(s[i])){
            xi=xi*10+s[i]-'0';
        }
        else if(isalpha(s[i])){
            c=s[i];
            xi*=sig;
            if(xi==0) xi=sig;
            xishu+=xi;
            sig=1;
            xi=0;
        }
        else {
            if(xi!=0){
                xi*=sig;
                chang-=xi;
                sig=1;
                xi=0;
            }
            if(s[i]=='+') sig=1;
            else sig=-1;
        }
    }
    if(xi!=0) chang-=(sig*xi);
    xi=0,sig=1;
    i++;
    for(;i<len;i++){
        if(isdigit(s[i])){
            xi=xi*10+s[i]-'0';
        }
        else if(isalpha(s[i])){
            c=s[i];
            xi*=sig;
            if(xi==0) xi=sig;
            xishu-=xi;
            sig=1;
            xi=0;
        }
        else {
            if(xi!=0){
                xi*=sig;
                chang+=xi;
                sig=1;
                xi=0;
            }
            if(s[i]=='+') sig=1;
            else sig=-1;
        }
    }
    if(xi!=0) chang+=(sig*xi);
    ans=(double)chang/xishu;
    //printf("%d %d\n",chang,xishu);
    printf("%c=%.3f\n",c,ans);
    return 0;
}
