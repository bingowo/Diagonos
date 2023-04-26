#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[10000];
    char a[10000];
    scanf("%s",s);
    int len=strlen(s);
    int k=0;
    int d;
    for(int j=2;j<len;j++)
    {
        if(s[j]>='A')
            d=s[j]-'A'+10;
        else
            d=s[j]-'0';
        unsigned int ex=0x8;
        while(ex)
        {
            if(d&ex) a[k++]='1';
            else a[k++]='0';
            ex=ex>>1;
        }
    long long int qr=0,qi=0;
    long long int c,d;
    for(int x=0;x<k;x++)
    {
        int v=a[x]-'0';
        c=-qr-qi+v;
        d=qr-qi;
        qr=c;
        qi=d;
    }
    if(qi==0)
    {
        printf("%lld",qr);
    }
    else
    {
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0)
                printf("+");
        }
        if(qi==1)
            printf("i");
        else if(qi==-1)
            printf("-i");
        else
        {
            printf("%lldi",qi);
        }
    }
    return 0;
}
}