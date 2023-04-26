#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int k=0,i,r;
    long long int qr=0,qi=0;
    long long int a,b;
    char s[50],t[150];
    scanf("%s",s);
    for(i=2;i<strlen(s);i++)  //16进制转转为2进制
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;  
        }
    }//数组s存放16进制(去掉0x)，数组t存放转换后的2进制

    for(i=0;i<k;i++)   //计算复数整数
    {
        r=t[i] - '0';
        a= -qr-qi+r;
        b= qr-qi;
        qr=a;
        qi=b;
    }
    if(a == 0 && b == 0)
        printf("0");
    else if(a == 0 && b != 0)
    {
        if(b < 0 && b != -1)
            printf("%lldi",b);
        else if(b > 0 && b != 1)
            printf("%lldi",b);
        else
        {
            if(b == -1)
                printf("-i");
            else
                printf("i");
        }
    }
    else if(a !=0)
    {
        printf("%lld",a);
        if(b < 0 && b != -1)
            printf("%lldi",b);
        else if(b > 0 && b != 1)
            printf("+%lldi",b);
        else
        {
            if(b == -1)
                printf("-i");
            else if(b == 1)
                printf("+i");

        }
    }
    return 0;
}
