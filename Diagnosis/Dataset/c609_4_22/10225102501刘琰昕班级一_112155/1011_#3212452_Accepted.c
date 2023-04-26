#include <stdio.h>
#include <stdlib.h>

void getnumber(const char *number,long long *numA,long long *numB,long long *numC)
{
    char *p=number;
    while(*p!='.'&&*p)//获取十进制整数部分
    {
        (*numA)*=3;
        if(*p=='0')(*numA)+=0;
        else if(*p=='1')(*numA)+=1;
        else (*numA)-=1;
        p++;
    }
    if(*p=='.')//获取十进制小数部分对应的分子与分母
    {
        p++;
        while(*p)
        {
            (*numB)*=3;
            if(*p=='0')(*numB)+=0;
            else if(*p=='1')(*numB)+=1;
            else (*numB)-=1;
            (*numC)*=3;
            p++;
        }
    }
}

long long gcd(long long y,long long x)
{
    long long t=0;
    y=y<0?-y:y;
    while(y)
    {
        long long digit=x;
        x=y;
        y=digit%y;
    }
    return x;
}

int main()
{
    char number[40]={0};//直接存获取的数字
    long long numA=0,numB=0,numC=1,t=1;//A为十进制整数部分,B为十进制小数部分分子,C为十进制小数部分分母
    scanf("%s",number);
    getnumber(number,&numA,&numB,&numC);
    if(numA>0&&numB<0)
        {numA--;numB=numB+numC;}
    else if(numA<0&&numB>0)
        {
            numA++;numB=-numB+numC;
            if(numA==0)numB=-numB;
        }
    t=gcd(numB,numC);
    if(numB==0)printf("%lld",numA);
    else
    {
        if(numA!=0)printf("%lld ",numA);
        printf("%lld %lld",numB/t,numC/t);
    }
}
