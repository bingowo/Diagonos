#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[20]={'\0'};
    scanf("%s",s);
    char p[100]={'\0'};
    for(int i=2;i<strlen(s);i++){
        int x;
        if(isdigit(s[i]))x=s[i]-48;
        if(isupper(s[i]))x=s[i]-55;
        char ss[5];
        for(int j=0;j<3;j++){
            ss[j]=0;
        }
        ss[4]='\0';
        for(int j=3;j>=0;j--){
            ss[j]=x%2;
            x=x/2;
        }
        strcat(p,ss);
    }
    int len=strlen(p);
    long long int a=1,b=0;
    for(int i=len-1;i>=0;i++){
        long long int m=a,n=b;
        a=-m-n;
        b=m-n;
        if(p[i]==1){
            a=a-1;
            b=b+1;
        }
    }
    printf("%lld %lld",a,b);
}