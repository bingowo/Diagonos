#include<stdio.h>
#include<ctype.h>
#define N 100

void readpoly(char *p, int* co)
{
    while (*p)
    {
        int sign=1,c=0,d=0;//sign用来存储符号,c存储系数,d存储指数
        if (*p=='+' ) p++;
        else if (*p=='-')
            sign=-1,p++;
        while (isdigit(*p))//isdigit()用来判断是否为数字
        {
            c=c*10+*p-'0';
            p++;
         }
        if (*p!='x')
        {
            co[0]=c*sign;
            return;
        }
        else p++;
        if (c==0) c=1;
        if (*p=='^') p++;
        while (isdigit(*p))
        {
            d=d*10+*p-'0'; p++;
        }
        if (d==0) d=1;
        co[d]=c*sign;
    }
}

void multiply(char *s1,char *s2, int* co)//计算多项式乘法
{
    int co1[N]={0},co2[N]={0};
    readpoly(s1,co1);
    readpoly(s2,co2);
    for (int i=0;i<N/2;i++)
    {
       for (int j=0;j<N/2;j++)
            co[i+j]+=co1[i]*co2[j];
    }
}

int main()
{
    char s1[N+1],s2[N+1];
    while(scanf("%s %s",s1,s2)==2)
    {
       int co[N]={0},out[N],n=0,i;
       multiply(s1,s2,co);
       for (i=0;i<N;i++)
       {
           if (co[i]) out[n++]=co[i];
       }
       for (i=n-1;i>=0;i--)
       {
            printf("%d",out[i]);
            if (i>0) printf(" ");
            else printf("\n");
       }
    }
    return 0;
}


