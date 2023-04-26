#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 501
#define M 168000000
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
    for(j=0;j<=2;j++)
    {
        p=t[j];
        t[j]=t[4-j];
        t[4-j]=p;
    }
    t[5]='\0';
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
        t[j]=t[7-j];
        t[7-j]=p;
    }
    t[8]='\0';
}

int main()
{
    char s[N],t[11],f[M],g[11],l[8],r[5];
    int i,j,n,sum,d,k,h;
    scanf("%s",s);
    num(strlen(s),t);
    if(strlen(s)%3==0)
    {
        for(i=0,k=0;i<strlen(s);i+=3,k++)
         {
            sum=s[i]*100+s[i+1]*10+s[i+2];
            num(sum,g);
            for(h=10+k*10,j=0;j<10;j++,h++)
               f[h]=g[j];
          }
    }
    else if(strlen(s)%3==1)
    {
        for(i=0,k=0;i<strlen(s)-1;i+=3,k++)
         {
            sum=s[i]*100+s[i+1]*10+s[i+2];
            num(sum,g);
            for(h=10+k*10,j=0;j<10;j++,h++)
              f[h]=g[j];
          }
          d=s[strlen(s)-1];
          num1(d,r);
          for(h=10+k*10,j=0;j<7;j++,h++)
            f[h]=r[j];
    }
     else if(strlen(s)%3==2)
    {
        for(i=0,k=0;i<strlen(s)-2;i+=3,k++)
         {
            sum=s[i]*100+s[i+1]*10+s[i+2];
            num(sum,g);
            for(h=10+k*10,j=0;j<10;j++,h++)
              f[h]=g[j];
          }
          d=s[strlen(s)-2]*10+s[strlen(s)-1];
          num2(d,l);
          for(h=10+k*10,j=0;j<7;j++,h++)
            f[h]=l[j];
    }
    else if(strlen(s)%3==1)
    {
        for(i=0,k=0;i<strlen(s)-1;i+=3,k++)
         {
            sum=s[i]*100+s[i+1]*10+s[i+2];
            num(sum,g);
            for(h=10+k*10,j=0;j<10;j++,h++)
              f[h]=g[j];
          }
          d=s[strlen(s)-1];
          num1(d,r);
          for(h=10+k*10,j=0;j<4;j++,h++)
            f[h]=r[j];
    }
    for(n=0;n<10;n++)
        f[n]=t[n];
    printf("0001%s",f);
    return 0;
}
