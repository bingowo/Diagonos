#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
void readpoly(char *s, int* co)//解析多项式(利用指针，将参数返回)
{  while (*s)
   {  int sign=1,coef=0,dim=0;
      if (*s=='+' )
        s++;
      else if (*s=='-')
        {sign=-1;s++;}
      while (*s>='0'&&*s<='9') {  coef=coef*10+*s-'0'; s++; }//将连续的数字转换成十进制***********
      if (coef==0) coef=1;//+1,-1的情况
      if (*s!='x') { co[0]=coef*sign; return; } //计算系数的值，指数为0时，系数如前
      else s++;//如果没有x说明是单系数，有x则继续计算指数数
      if (*s=='^') s++;//指数
      while (*s>='0'&&*s<='9') {  dim=dim*10+*s-'0'; s++; }//将连续的指数转化为十进制数字***********
      if (dim==0) dim=1;
      co[dim]=coef*sign;//指数的值与系数的值联系起来，指数为dim时，系数如前
    }
}
void multiply(char *s1,char *s2, int* result)//实现多项式相乘
{
   int co1[50]={0},co2[50]={0};
   readpoly(s1,co1);
   readpoly(s2,co2);//解析两个多项式
   for (int i=0;i<50;i++)
     for (int j=0;j<50;j++)
        result[i+j]+=co1[i]*co2[j];//指数相加，系数相乘
}
int main()
{   char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)==2)//成功输入两个字符串
    {   int result[102]={0};
        multiply(s1,s2,result);//两个多项式相乘
        int flag=0;
        for (int i=99;i>=0;i--)//倒叙输出，两个50相加，最多100个
        { if (result[i])//系数不为0时
            {
            flag?printf(" %d",result[i]):printf("%d",result[i]);//第一个不用空格，第一个之后输出时有空格
            flag=1;
            }
        }
        printf("\n");//每一次之后输出换行符

    }

}
