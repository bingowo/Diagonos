#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000],t[1000];
    scanf("%s",&s);
    int k=0,d;
    //16进制转为2进制
    for(int i=2;i<strlen(s);i++)
    {
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag>>=1;
        }
    }//数组s存放16进制(去掉0x)，数组t存放转换后的2进制

    long long qr=0,qi=0,a,b;
    for(int i=0;i<k;i++)   //计算复数整数
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    //输出，没有虚部
    if(qi==0) printf("%lld\n",qr);
    //输出，有虚部
    else
    {
        if(qr!=0)  //有实部
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