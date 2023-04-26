#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char s[1000]={0},t[4000]={0};
    scanf("0x%s",s);
    //16进制转转为2进制
    //数组s存放16进制(去掉0x)，数组t存放转换后的2进制
    int k=0;//用于记录2进制的位数
    for(int i=0;i<strlen(s);i++)
    {
        int d;
        if(isupper(s[i]))d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag)t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;
        }
    }
    //计算复数整数
    long long qr=0,qi=0;
    long long a,b;
    for(int i=0;i<k;i++)
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    //输出
    if(qi==0)//没有虚部
    {
        printf("%lld\n",qr);
    }
    else//有虚部
    {
        if(qr!=0)//有实部
        {
            printf("%lld",qr);
            if(qi>0)printf("+");
        }
        if(qi==1)printf("i\n");
        else if(qi==-1)printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
    return 0;
}