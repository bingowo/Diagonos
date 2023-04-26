#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[100],t[100];
    long long qr=0,qi=0,a,b;
    int k=0;
    scanf("%s",&s);
    for(int i=0;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;
        }
    }
    for(int i=0;i<k;i++)
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a; qi=b;
    }
    if(qi==0) printf("%lld",qr);
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else printf("%lldi\n",qi);
    }
    return 0;
}
