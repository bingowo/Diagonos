#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[20]={'\0'};
    scanf("%s",s);
    char p[200]={'\0'};
    for(int i=2;i<strlen(s);i++){
        int x;
        if(isdigit(s[i])){x=s[i]-48;}
        else if(isupper(s[i])){x=s[i]-55;}
        char ss[5]={'\0'};
        for(int j=0;j<4;j++){
            ss[j]='0';
        }
        for(int j=3;j>=0;j--){
            ss[j]=x%2+48;
            x=x/2;
        }
        strcat(p,ss);
    }
    int len=strlen(p);
    long long int a=1,b=0;
    long long int aa=0,bb=0;
    for(int i=len-1;i>=0;i--){
        if(p[i]=='1'){
            aa=aa+a;
            bb=bb+b;
        }
        long long int m=a,n=b;
        a=-m-n;
        b=m-n;
    }
    if(aa==0&&bb!=0);
    else printf("%lld",aa);
    if(bb==1){
        if(aa!=0)printf("+i");
        else printf("i");
    }
    else if(bb==-1)printf("-i");
    else if(bb>0)printf("+%lldi",bb);
    else if(bb<0) printf("%lldi",bb);
}
