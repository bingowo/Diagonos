#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 100

void ratio(char *p,int *co)//用这个函数判断每一项前的系数
{
    while(*p)
    {
        int sign=1,c=0,d=0;//表示符号，默认sign是正的，读到‘-’再变成-1
        if(*p=='+')p++;
        else if(*p=='-')sign=-1,p++;
        while(isdigit(*p)){c=c*10+*p-'0';p++}//如果读到的是数字，计算系数
        if(*p!='x'){co[0]=c*sign;return;}else p++;//如果读到的不是x，就说明是一个常数
        if(c==0)c=1;//x的系数为正负1时没有额外的系数
        if(*p=='^')p++;
        while(isdigit(*p)){d=d*10+*p-'0';p++;}
        if(d==0)d=1;
        co[d]=c*sign;
    }
}

void multiply(char *s1,char *s2,int *co)
{
    int co1[N]={0},co2[N]={0},i,j;
    ratio(s1,co1);ratio(s2,co2);
    for(i=0;i<N/2;i++)
        for(j=0;j<N/2;j++)
        co[i+j]=co1[i]*co2[j];
}

int main()
{
    char s1[N+1],s2[N+1];//输入两个多项式
    while(scanf("%s%s",s1,s2)==2)//scanf会返回它成功输入的个数，scanf==2表示两个都输入成功了
    {
        int co[N]={0},out[N],n=0,i;
        multiply(s1,s2,co);
        for(i=0;i<N;i++)if(co[i])out[n++]=co[i];
        for(i=n-1;i>=0;i--)
        {
            printf("%d",out[i]);
            if(i>0)printf(" ");else printf("\n");
        }

    }
    return 0;

}

