#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[100];
    char a[100];
    scanf("%s",s);
    int len=strlen(s);
    int k=0;
    for(int j=2;j<len;j++)
    {
        if(s[j]>='A')
            s[j]=s[j]-'A'+10;
        else
            s[j]=s[j]-'0';
        unsigned int ex=0x8;
        while(ex)
        {
            if(s[j]&ex) a[k++]='1';
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