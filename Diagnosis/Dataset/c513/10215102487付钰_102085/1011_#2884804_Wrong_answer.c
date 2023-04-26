#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    char s[1000];
    scanf("%s",&s);
    int k=0,t[100000];
    for(int i=0;i<strlen(s);i++) //16进制转转为2进制
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=8;//?
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;
        }
    } //数组s存放16进制(去掉0x)，数组t存放转换后的2进制
    long long int qr=0,qi=0;
    long long int a,b;
    int j;
    for(int j=0;j<k;j++) //计算复数整数
    {
        int r=t[j]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(qi==0) //输出，没有虚部
    {printf("%lld\n",qr);}
    else //输出，有虚部
    {
        if(qr!=0) //有实部
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
}
