#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s0[100];
    scanf("%s",s0);
    int length=strlen(s0),i=0;
    long long int a=0,b=0;
    int sig1=1,sig2=1,sig=1;
    if(isdigit(s0[0])){
        long long int x=0;
        while(isdigit(s0[i])&&(i<length)){
            x=x*10+s0[i]-'0';
            i++;
        }
        if (i==length) a=sig1*x;
        else if(s0[i]=='i') {b=sig2*x;i++;}
        else if(s0[i]=='+'||s0[i]=='-') a=sig1*x;
    }
    else if (s0[0]=='i') b=1;
    else if (s0[0]=='-'){
        i++;
        sig=-1;
        if(s0[i]=='i') {b=-1;i++;}
        else{
            long long int x=0;
            while(isdigit(s0[i])&&(i<length)){
                x=x*10+s0[i]-'0';
                i++;
            }
            if (i==length) a=sig*x;
            else if(s0[i]=='i') {b=sig*x;i++;}
            else a=sig*x;
        }
    }
    if(i<length){
        sig2= s0[i]=='+' ? 1 : -1;
        i++;
        if(s0[i]=='i') {b=sig2;i++;}
        else {
            long long int x=0;
            while(isdigit(s0[i])&&(i<length)){
                x=x*10+s0[i]-'0';
                i++;
            }
            b=sig2*x;
        }
    }
    char s1[1000];
    int r=(llabs(a+b))%2;
    int j=0;
    while(!(a==0&&b==0)){
        long long int a1=a,b1=b;
        b=(r-a1-b1)/2;
        a=(r-a1+b1)/2;
        s1[j]='0'+r;
        r=llabs((a+b))%2;
        j++;
    }
    s1[j]=0;
    for (int k=0;k<j;k++) printf("%c",s1[j-1-k]);
    return 0;
}
