#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void reverse4(char* a)
{
    int i,j;
    char s;
    for(i=0,j=6;i<j;i++,j--)
    {
        s=a[i];
        a[i]=a[j];
        a[j]=s;
    }
}

void reverse3(char* a)
{
    int i,j;
    char s;
    for(i=0,j=3;i<j;i++,j--)
    {
        s=a[i];
        a[i]=a[j];
        a[j]=s;
    }
}

void reverse2(char* a)
{
    int i,j;
    char s;
    for(i=0,j=9;i<j;i++,j--)
    {
        s=a[i];
        a[i]=a[j];
        a[j]=s;
    }
}

void reverse(char* a)
{
    int i,j;
    char s;
    for(i=0,j=strlen(a)-1;i<j;i++,j--)
    {
        s=a[i];
        a[i]=a[j];
        a[j]=s;
    }
}

int main()
{
    char a[1000];
    scanf("%s",a);   //输入一串数字，作为字符存储在a中
    int l,n=0,i,j;
    l=strlen(a);   //求a的长度
    int l2=l;
    if(l<=3)
    {
        for(i=0;i<l;i++)
            n=10*n+a[i]-48;
        char b[100];
        for(i=0;n>0||i<(3*l2+1);i++)
        {
            b[i]=n%2+48;
            n=n/2;
        }
        for(;l>0||i<(3*l2+11);i++)
        {
            b[i]=l%2+48;
            l=l/2;
        }
        b[i++]='1';
        for(;i<(3*l2+15);i++)
            b[i]='0';
        b[i]='\0';
        reverse(b);
        for(i=0;b[i];i++)
            printf("%c",b[i]);
    }
    else   //如果输入的数字个数大于3
    {
        int N,M;
        N=l/3;    //需要多少个3组
        M=l%3;   //最后一组有多少个数字
        if(M==0)  //如果刚好一共有N组3个数
        {
            char c[N][10];  //N行，每行存储每个数字的二进制
            j=0;
            for(i=0;i<N;i++)  //取二维数组的一行来存放三个数字的二进制
            {
                n=0;
                for(;j<3*(i+1);j++)  //j不能取0，下一次循环要从现在的j开始往后数三个
                {
                    n=n*10+a[j]-48;   //每三位组成的数字
                }
                int k;
                for(k=0;k<10;k++)
                {
                    c[i][k]=n%2+48;
                    n=n/2;
                }
                reverse2(c[i]);
            }
            char d[10000];
            for(i=0;i<10;i++)
            {
                d[i]=l2%2+48;
                l2=l2/2;
            }
            d[i++]='1';
            for(;i<14;i++)
                d[i]='0';
            reverse(d);
            int k;
            for(j=0;j<N;j++)
            {
                for(k=0;k<10;k++,i++)
                    d[i]=c[j][k];
            }
            for(i=0;d[i];i++)
                printf("%c",d[i]);
        }
        else
        {
            if(M==1)
            {
                char c[N+1][10];
                j=0;
                for(i=0;i<N;i++)  //取二维数组的一行来存放三个数字的二进制
                    {
                        n=0;
                        for(;j<3*(i+1);j++)  //j不能取0，下一次循环要从现在的j开始往后数三个
                            {
                                n=n*10+a[j]-48;   //每三位组成的数字
                        }
                        int k;
                        for(k=0;k<10;k++)
                            {
                                c[i][k]=n%2+48;
                                n=n/2;
                                }
                                reverse2(c[i]);
                    }
                    int k;
                for(k=0;k<4;k++)
                {
                    c[N][k]=a[j]%2+48;
                    a[j]=a[j]/2;
                }
                reverse3(c[N]);
                char d[1000];
                for(i=0;i<10;i++)
                    {
                        d[i]=l2%2+48;
                        l2=l2/2;
                    }
                d[i++]='1';
                for(;i<14;i++)
                    d[i]='0';
                reverse(d);
                for(j=0;j<N+1;j++)
            {
                for(k=0;k<10;k++,i++)
                    d[i]=c[j][k];
            }
            for(i=0;d[i];i++)
                printf("%c",d[i]);
        }
        else
        {
                char c[N+1][10];
                j=0;
                for(i=0;i<N;i++)  //取二维数组的一行来存放三个数字的二进制
                    {
                        n=0;
                        for(;j<3*(i+1);j++)  //j不能取0，下一次循环要从现在的j开始往后数三个
                            {
                                n=n*10+a[j]-48;   //每三位组成的数字
                        }
                        int k;
                        for(k=0;k<10;k++)
                            {
                                c[i][k]=n%2+48;
                                n=n/2;
                                }
                                reverse2(c[i]);
                    }
                    int k;
                    n=0;
                for(;j<(3*i+2);j++)
                    n=10*n+a[j]-48;
                for(k=0;k<7;k++)
                {
                    c[N][k]=n%2+48;
                    n=n/2;
                }
                reverse4(c[N]);
                char d[1000];
                for(i=0;i<10;i++)
            {
                d[i]=l2%2+48;
                l2=l2/2;
            }
            d[i++]='1';
            for(;i<14;i++)
                d[i]='0';
            reverse(d);
            for(j=0;j<N+1;j++)
            {
                for(k=0;k<10;k++,i++)
                    d[i]=c[j][k];
            }
            for(i=0;d[i];i++)
                printf("%c",d[i]);
        }
        }
    }
}

