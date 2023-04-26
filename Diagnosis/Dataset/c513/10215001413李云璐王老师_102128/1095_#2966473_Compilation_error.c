#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{   char l2,l1;
    scanf("%c%c",&l1,&l2);
    char s[10000];
    scanf("%s",&s);
    char t[10000];
    int a[1200]={0},b[1200]={0},qr[1200]={0},qi[1200]={0};
    int k=0;
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
     
    for(int i=0;i<k;i++)   //计算复数整数
    {
        int r=t[i]-'0';
        int wei1,wei2
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }