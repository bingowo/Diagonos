#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxstr 500
int main(){
    char s[maxstr],t[maxstr];
    scanf("%s",s);
//    for(int a=0;a<maxstr;a++)t[a]='0';
    int ti=0;
    for(int i=2;i<strlen(s);i++){
        int n;
        if(s[i]>='A')n=s[i]+10-'A';
        else n=s[i]-'0';
        int flag=8;
        while(flag){
            if(n&flag)t[ti++]='1';
            else t[ti++]='0';
            flag=flag>>1;
        }
    }
    t[ti]='\0';
    long long int a,b;
    long long int qr=0,qi=0;
    for(int j=0;j<strlen(t);j++){
        long long int n=t[j]-'0';
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
