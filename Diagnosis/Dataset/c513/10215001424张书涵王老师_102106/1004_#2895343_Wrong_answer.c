#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reverse(char* s)
{
    int i,j;
    char c;
    for(i=0,j=7;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

void reverse1(char* c)
{
    char s;
    s=c[0];
    c[0]=c[1];
    c[1]=s;
}

void zhengshu(int n)
{
    char s[4][8];
    char c[4][2];
    int i,j;
    if(n>=0)
    {
        for(i=0;i<4;i++)
            {
                for(j=0;j<8;j++)
                {
                    s[i][j]=n%2+48;
                    n=n/2;
                }
                reverse(s[i]);
            }
    }
    else
    {
        int k=0;
        n=(-1)*n;
        char s2[100];
        for(i=0;i<32;i++)
        {
            s2[i]=n%2+48;
            n=n/2;
            if(s2[i]=='0')
                s2[i]='1';
            else
                s2[i]='0';
        }
        s2[0]=s2[0]+1;
        for(i=0;s2[i]=='2';i++)
        {
            s2[i]='0';
            s2[i+1]=s2[i+1]+1;
        }
        for(i=0;i<4;i++)
            for(j=0;j<8;j++,k++)
        {
            s[i][j]=s2[k];
        }
        for(i=0;i<4;i++)
            reverse(s[i]);
    }
    n=0;
    for(i=0;i<4;i++)//对每一行进行操作，得出每一行的二进制转化成十六进制的值
    {
        for(j=0;j<8;j++)
        {
            n=n*2+s[i][j]-48;//求每一行，也就是每一个字节对应的整数值
        }
        for(j=0;j<2;j++)
        {
            if((n%16)>10)
            {
                c[i][j]=n%16+87;
                n=n/16;
            }
            else
            {
                c[i][j]=n%16+48;
                n=n/16;
            }
        }
        reverse1(c[i]);
        for(j=0;j<2;j++)
            printf("%c",c[i][j]);
        printf(" ");
    }
}

void fudianshu()
{
}

int main()
{
    char s[1000];
    while (scanf("%s",s)!=EOF)
    {
        int i;
        for(i=0;s[i];i++)
        {
            if(s[i]=='.')
                fudianshu(atof(s));
        }
        zhengshu(atoi(s));
        return 0;
    }
}

