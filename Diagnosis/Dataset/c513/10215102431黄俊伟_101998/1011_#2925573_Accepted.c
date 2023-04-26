#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int qr=0,qi=0;
    long long int a,b;
    int k=0;
    char s[40];
    char t[160];
    scanf("%s",s);
    for(int i=2;i<strlen(s);i++)
    {
        int d;
        if(s[i]>='A')
            d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag)
                t[k++]='1';
            else
                t[k++]='0';
            flag=flag>>1;
        }
    }
    for(int i=0;i<k;i++)
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    if(qi==0)
    {
        printf("%lld\n",qr);
    }
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
    return 0;
}