#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long R(long long x, long long y) {
    if((x-y)%2!=0) return 1;
    else return 0;
}
int main() {
    char s[5000];
    scanf("%s",s); //a+bi=(qr+qli)*(-1+i)+r 得 qr=(r-a+b)/2, qi=(r-a-b)/2
     char*p;
     long long qr,qi,qrr,qii,r,d=0;
     if(strchr(s,'i')==NULL) qr=atoll(s),qi=0; //only a
     else if(s[0]=='i') qr=0,qi=1;
     else if(strchr(s,'i')&&s[0]!='i'
     &&strchr(s,'+')==NULL&&strchr(s,'-')==NULL) {
        p=strchr(s,'i');
        *p='\0';
        qr=0,qi=atoll(s);
     }
     else if(strchr(s,'i')&&s[0]!='i') {
        p=strchr(s,'i');
        *p='\0';
        p=p-1;
        int j=strlen(s)-1,l;
        l=j;
         for(;*p!='+'&&*p!='-'&&j!=-1;j--,p--);
        if(*p=='+'&&j==l) d=1,qi=1;
        else if(*p=='-'&&j==l&&j>0) d=l, qi=-1;
        else if(*p=='-'&&j==l&&j==0) qr=0, qi=-1;
        else if(j==-1) qr=0,qi=atoi(s);
        else if(*p=='-'&&j<l&&j==0) qr=0,qi=atoll(s);
        else if(*p=='-'&&j<l&&j>0) d=1,qi=atoll(p);
        else if(*p=='+'&&j<l) {
            d=1;qi=atoll(p);
        }
        else if(j==-1&&l>0) qr=0,qi=atoll(p+1);
        if(d==1) {
            *p='\0';
            qr=atoll(s);
        }
     }

    long long i[5000]={0};
     int n=0;
     do{
        r=R(qr,qi);
        i[n++]=r;
        qrr=qr;
        qii=qi;
        qr=(r-qrr+qii)/2,qi=(r-qrr-qii)/2;
     }while(qr!=0||qi!=0);
     for(n=n-1;n>=0;n--) {
        printf("%lld",i[n]);
     }
        return 0;
}