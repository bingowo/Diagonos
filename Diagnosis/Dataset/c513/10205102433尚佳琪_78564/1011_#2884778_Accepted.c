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
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]=1;
            else t[k++]=0;
            flag=flag>>1;
        }
    }

    /*for(int i=0;i<k;i++)
       printf("%d",t[i]);
    printf("\n");*/
    return k;
}
int main()
{
    char s[50];
    int t[10000]={0};
    scanf("%s",s);
    int len=_16to2(s,t);
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
    else if(qi==0&&qr!=0)
        printf("%lld",qr);
    else if(qi==0&&qr==0)
        printf("0");
    else if(qi>0)
    {
        if(qi==1)
            printf("%lld+i",qr);
        else
            printf("%lld+%lldi",qr,qi);
    }
    else if(qi<0)
    {
        if(qi==-1)
            printf("%lld-i",qr);
        else
            printf("%lld%lldi",qr,qi);
    }
    return 0;
}
