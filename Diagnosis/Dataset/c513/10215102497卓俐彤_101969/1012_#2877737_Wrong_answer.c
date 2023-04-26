#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxstr 5000
int main(){
    char s[maxstr],t1[maxstr],t2[maxstr],t[maxstr];
    scanf("%s",s);
    long long int a=0,b=0;
    if(s[strlen(s)-1]!='i')a=atoll(s);
    else{
        if(s[0]=='i')b=1;
        else if(s[0]=='-'&&s[1]=='i')b=-1;
        else{
            char *p=s;
            int i=0;
            if(*p=='-')t1[i++]=*p++;
            while(*p!='-'&&*p!='+'){
                t1[i++]=*p++;
            }
            t1[i]='\0';
            i=0;
            if(*p=='-')t2[i++]=*p++;
            else p++;
            if(*p=='i')t2[i++]='1';
            while(*p!='i'){
                t2[i++]=*p++;
            }
            t2[i]='\0';
            a=atoll(t1);
            b=atoll(t2);
        }
    }
    long long int qr=a,qi=b;
    int ti=0;
    
    while(a!=0||b!=0){
        if(a<0)a=-a;
        if(b<0)b=-b;
        long long int n=(a%2!=b%2);
        a=(n+qi-qr)/2;
        b=(n-qi-qr)/2;
        qr=a;
        qi=b;
        t[ti++]=n+'0';
    }
    t[ti]='\0';
    for(int j=0;j<strlen(t);j++)printf("%c",t[strlen(t)-1-j]);
    printf("\n");

    return 0;
}
