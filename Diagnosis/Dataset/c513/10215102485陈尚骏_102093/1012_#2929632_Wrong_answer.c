#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

long long G(long long a,long long b)
{
    if((a-b)%2!=0) return 1;
    else return 0;
}

int main()
{
    char s[5001];
    scanf("%s",s);
    char *p;
    long long qr,qi,qrr,qii,r,a=0;
    if(strchr(s,'i')==NULL) {qr=atoll(s);qi=0;}
    else if(s[0]=='i') {qr=0;qi=1;}
    else if(strchr(s,'i')&&s[0]!='i'&&strchr(s,'+')==NULL&&strchr(s,'-')==NULL)
    {
        p=strchr(s,'i');
        *p='\0';
        qr=0;
        qi=atoll(s);
    }
    else if(strchr(s,'i')&&s[0]!='i')
    {
        p=strchr(s,'i');
        *p='\0';
        p=p-1;
        int l,j=strlen(s)-1;
        l=j;
        for(;*p!='+'&&*p!='-'&&j!=-1;j--,p--);
        if(*p=='+'&&j==l) {a=1;qi=1;}
        else if(*p=='-'&&j==l&&j>0){a=1;qi=-1;}
        else if(*p=='-'&&j==l&&j==0) {qr=0;qi=-1;}
        else if(j==-1) {qr=0;qi=atoi(s);}
        else if(*p=='-'&&j<l&&j==0) {qr=0; qi=atoll(s);}
        else if(*p=='-'&&j<l&&j>0) {a=1;qi=atoll(p);}
        else if(*p=='+'&&j<l){a=1;qi=atoll(p);}
        else if(j==-1&&l>0){qr=0;qi=atoll(p+1);}
        if(a==1){*p='\0';qr=atoll(s);}
        long long d[5001]={0};
        int k=0;
        do
        {
            r=G(qr,qi);
            d[k++]=r;
            qrr=qr;
            qii=qi;
            qr=(r-qrr+qii)/2;
            qi=(r-qrr-qii)/2;
        }while(qr!=0||qi!=0);
        for(k=k-1;k>=0;k--) printf("%lld",d[k]);
    }
    return 0;
}
