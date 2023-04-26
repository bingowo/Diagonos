#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 501
#define M 10000
void num(int n,char t[11])
{
    int a,i,j;char p;
    for(i=0;i<11;i++)t[i]=0;
    for(i=0;i<10;i++)
    {
        a=n%2;
        n=n/2;
        t[i]=a+'0';
    }
    for(j=0;j<=4;j++)
    {
        p=t[j];
        t[j]=t[9-j];
        t[9-j]=p;
    }
    t[10]='\0';
}

void num1(int n,char t[5])
{
    int a,i,j;char p;
    for(i=0;i<5;i++)t[i]=0;
    for(i=0;i<4;i++)
    {
        a=n%2;
        n=n/2;
        t[i]=a+'0';
    }
    for(j=0;j<=1/*要小于等于数组最后一个[数]的一半*/;j++)
    {
        p=t[j];
        t[j]=t[3-j];
        t[3-j]=p;
    }
    t[4]='\0';
}


void num2(int n,char t[8])
{
    int a,i,j;char p;
    for(i=0;i<8;i++)t[i]=0;
    for(i=0;i<7;i++)
    {
        a=n%2;
        n=n/2;
        t[i]=a+'0';
    }
    for(j=0;j<=3;j++)
    {
        p=t[j];
        t[j]=t[6-j];
        t[6-j]=p;
    }
    t[7]='\0';//最后要有结束符！
}
int main()
{
    char s[N],t[11],f[M],g[11],l[8],r[5];
    int i,j,n,sum,d,k,p;
    scanf("%s",s);
    p=strlen(s);
    num(p,t);
     for(n=0;n<10;n++)
        f[n]=t[n];
    if(p%3==0)
    {
        for(i=0,k=0;i<p;i+=3,k++)
         {
            sum=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';//虽然s[i]可以直接看成值，但这个值是他的ASCII值，不是本身值
            num(sum,g);
            for(n=10+k*10/*可以是固定值也可以是计算值*/,j=0;j<10;j++,n++)
               f[n]=g[j];
          }
    }

     else if(p%3==2)
    {
        for(i=0,k=0;i<p-2;i+=3,k++)
         {
            sum=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
            num(sum,g);
            for(n=10+k*10,j=0;j<10;j++,n++)
              f[n]=g[j];
          }
          d=(s[p-2]-'0')*10+s[p-1]-'0';
          num2(d,l);
          for(n=10+k*10,j=0;j<7;j++,n++)
            f[n]=l[j];
    }
    else if(strlen(s)%3==1)
    {
        for(i=0,k=0;i<p-1;i+=3,k++)
         {
            sum=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
            num(sum,g);
            for(n=10+k*10,j=0;j<10;j++,n++)
              f[n]=g[j];
          }
          num1(s[p-1]-'0',r);
          for(n=10+k*10,j=0;j<4;j++,n++)
            f[n]=r[j];
    }
    printf("0001%s",f);
    return 0;
}
