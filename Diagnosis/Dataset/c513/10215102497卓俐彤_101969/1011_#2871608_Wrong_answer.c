#include <stdio.h>
#include <stdlib.h>

#define maxstr 64

int main(){
    char s[maxstr],t[maxstr]={'0'};
    scanf("%s",s);
    char *p=s+1;
    long long int num=0;
    while(*++p){
        if(*p>='A')num=num*16+*p-'A'+10;
        else num=num*16+*p-'0';
    }
    long long int flag=1;
    int i=maxstr;
    while(flag){
        if(num&flag)t[--i]='1';
        else t[--i]='0';
        flag=flag<<1;
    }
    long long int a,b;
    long long int qr=0,qi=0;
    for(int j=0;j<maxstr;j++){
        int n=t[j]-'0';
        a=-qr-qi+n;
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(qi==0)printf("%lld\n",qr);
    else{
        if(qr!=0){
        printf("%lld",qr);
        if(qi>0)printf("+");
    }
    if(qi==1)printf("i\n");
    else if(qi==-1)printf("-i\n");
    else printf("%lldi\n",qi);
    }
    return 0;
}


