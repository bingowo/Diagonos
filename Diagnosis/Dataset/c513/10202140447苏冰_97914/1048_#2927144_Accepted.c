#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
void read(char* s,int* t)
{
    while(*s)
    {
        int sign=1,zhi=0,xi=0;
        if(*s=='+') s++;
        else if(*s=='-')
        {
            sign=-1;s++;
        }
        while(isdigit(*s))
        {
            xi=xi*10+(*s-'0');s++;
        }
        if(xi==0) xi=1;
        if(*s!='x')
        {
            t[0]=sign*xi;return;
        }
        else s++;
        if(*s=='^') s++;
        while(isdigit(*s))
        {
            zhi=zhi*10+(*s-'0');
            s++;
        }
        if(zhi==0) zhi=1;
        t[zhi]=xi*sign;
    }
}//读取多项式的每一项，结果存在t里，t的下标对应的是指数，存的元素是对应的系数，
//从符号位，系数，指数的顺序计算
void multiply(char*s1,char*s2,int* result)
{
    int t1[50]={0},t2[50]={0};
    read(s1,t1);
    read(s2,t2);
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            result[i+j]+=t1[i]*t2[j];
        }
    }//多项式乘法
}
int main()
{
    char s1[110],s2[110];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int result[110]={0};
        multiply(s1,s2,result);
        int flag=0;
        for(int i=99;i>=0;i--)
        {
            if(result[i])
            {
                if(flag==0) printf("%d",result[i]);
                else printf(" %d",result[i]);
                flag=1;//最后一个数字后没有空格的新方法
            }
        }
        printf("\n");
    }
    return 0;
}
