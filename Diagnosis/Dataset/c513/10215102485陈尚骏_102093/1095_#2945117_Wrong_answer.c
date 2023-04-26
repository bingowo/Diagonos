#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[100001],t[100001];
    int i=0;
    scanf("%s",s);
    for(int j=2;j<strlen(s);j++)
    {
        int a;
        if(s[j]>='A') a=s[j]-'A'+10;
        else a=s[j]-'0';
        unsigned flag=0x8;
        while(flag)
        {
            if(a&flag) t[i++]='1';
            else t[i++]='0';
            flag=flag>>1;
        }
    }
    long long qr=0,qi=0;
    long long b,c;
    for(int k=0;k<i;k++)
    {
        int r=t[k]-'0';
        b=-qr-qi+r;
        c=qr-qi;
        qr=b;
        qi=c;
    }
    if(qi==0) printf("%lld",b);
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
