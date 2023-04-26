#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _16to2(char s[],int t[])
{
    int k=0;
    for(int i=2;i<strlen(s);i++) //16进制转转为2进制
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        int flag=8;
        while(flag)
        {
            if(d&flag) t[k++]=1;
            else t[k++]=0;
            flag=flag>>1;
        }
    }
    return k;
}

int main()
{
    char s[100];
    int t[1000]={0};
    scanf("%s",s);
    int len;
    len=_16to2(s,t);
    long long a,b,qr=0,qi=0;
    for(int i=0;i<len;i++)
    {
        a=-qr-qi+t[i];
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(qr==0&&qi!=0)
    {
        if(qi==1)
            printf("i");
        else if(qi==-1)
            printf("-i");
        else
            printf("%lldi",qi);
    }
    else if(qr!=0&&qi==0)
    {
        printf("%lld",qr);
    }
    else if(qr==0&&qi==0)
    {
        printf("0");
    }
    else
    {
        if(qi==1)
            printf("%lld+i",qr);
        else if(qi==-1)
            printf("%lld-i",qr);
        else if(qi<0)
            printf("%lld%lldi",qr,qi);
        else if(qi>0)
            printf("%lld+%lldi",qr,qi);
    }
    return 0;
}
