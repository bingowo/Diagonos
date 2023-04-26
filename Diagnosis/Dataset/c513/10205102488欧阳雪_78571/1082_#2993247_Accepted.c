#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX_LEN 10000    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX_LEN] = {0}     //高精度数的定义方式
int main()
{
    INT(x);
    INT(y);

    char s1[MAX_LEN],s2[MAX_LEN];
    int m1,m2,mmax,mmin,tem,remain,mm;     //小数点出现的位置
    int i,j,k;

    scanf("%s%s%d",s1,s2,&remain);

    for(m1=0;m1<strlen(s1)&&s1[m1]!='.';m1++);
    for(m2=0;m2<strlen(s2)&&s2[m2]!='.';m2++);

    if(m1>m2){
    	mmax=m1;
	}
	else mmax=m2;

    for(i=mmax+2,j=m1-1;j>=0;i--,j--)   x[i] = s1[j]-'0';  //对齐工作
    for(i=mmax+2,j=m2-1;j>=0;i--,j--)   y[i] = s2[j]-'0';

    x[mmax+3] = 999;
    y[mmax+3] = 999;

    for(i=mmax+4,j=m1+1;j<strlen(s1);i++,j++)  x[i] = s1[j]-'0';
    for(i=mmax+4,j=m2+1;j<strlen(s2);i++,j++)  y[i] = s2[j]-'0';


    for(k=MAX_LEN-1;k>=0;k--)//加法运算
    {
        if(x[k-1]==999) mm=2;  //999相当于小数点
        else mm=1;

        if(x[k]!=999)
        {
            x[k] = x[k]+y[k];
            if(x[k]>=10)//有进位
            {
                tem = x[k]/10;
                x[k]%=10;
                x[k-mm]+=tem;
            }
        }
    }

    k=mmax+3+remain; //不管整数部分有多少位，对齐后从mmax到小数部分走3位
    if(x[k+1]>=5)//末尾四舍五入
    {
        x[k]++;
        for(;k>=0;k--)//入了之后判断有无进位
        {
            if(x[k-1]==999) mm=2;
            else mm=1;
            if(x[k]>=10&&x[k]!=999)
            {
                tem = x[k]/10;
                x[k]%=10;
                x[k-mm]+=tem;
            }
            //else break;
        }
    }

    for(k=0;x[k]==0;k++);
    if(x[k]!=999)//输出整数部分
        for(;x[k]!=999;k++) printf("%d",x[k]);
    else printf("0");  //整数部分为0
    printf(".");
    k++;

    int g;
    for(g=0;g<remain;g++,k++)   printf("%d",x[k]);  //输出小数部分后N位

    return 0;
}
