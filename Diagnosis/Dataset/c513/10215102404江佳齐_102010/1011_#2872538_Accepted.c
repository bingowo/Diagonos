#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[10000],t[10000];
    int k=0;
    long long int a,b,qr=0,qi=0;
    scanf("0x%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int f=0x8;
        while(f)
        {
            if(d&f) t[k++]='1';
            else t[k++]='0';
            f=f>>1;
        }
    }
    for(int i=0;i<k;i++)
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qi=b;
        qr=a;
    }
    if(qi==0) printf("%lld\n",qr);
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else
        {
            printf("%lld",qi);
            printf("i\n");
        }
    }
    return 0;
}
