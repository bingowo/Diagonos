#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>
int main()
{
    char s1[101];
    scanf("%s",s1);
    char s[101];
    for(int i=2;i<strlen(s1);i++)
    s[i-2]=s1[i];
    int k=0;
    int t[101];
    for(int i=0;i<strlen(s);i++)  //16进制转转为2进制
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
    }   //数组s存放16进制(去掉0x)，数组t存放转换后的2进制

    unsigned long long int qr=0,qi=0;
    unsigned long long int a,b;
    for(int i=0;i<k;i++)   //计算复数整数
    {
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }

    if(qi==0)     //输出，没有虚部
    {
        printf("%u\n",qr);
    }
    else       //输出，有虚部
    {
        if(qr!=0)  //有实部
        {
            printf("%u",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%u",qi);printf("i\n");}
    }

}