#include <stdio.h>
#include <stdlib.h>

int zuidagys(int a,int b)
{
    int m,n,k;
    m=a;
    n=b;
    while((m%n)!=0)
    {
        k=m;
        m=n;
        n=k%n;
    }
    return n;
}

void erjinzhi(char* a,char* b)   //a数组存储的是一行的字符，b数组存储的是这一行字符串的二进制
{
    int i,j=0,l;
    for(i=0;a[i];i++)
    {
        l=a[i];
        for(;j<8*(i+1);j++)   //每个字符存储八位的二进制
        {
            b[j]=l%2+48;
            l=l/2;
        }
    }
}

int main()
{
    char b[10000];
    int T,l=0,o=0,z;
    int r;
    scanf("%d ",&T);
    char a[T][1000];
    int i,j;
    for(i=0;i<T;i++)
      gets(a[i]);
    for(i=0;i<T;i++)
    {
        l=0;o=0;
        erjinzhi(a[i],b);   //求一行字符的二进制
        for(j=0;b[j];j++)   //判断二进制中0和1的数量
        {
            if(b[j]=='1')
                l=l+1;
            else
                o=o+1;
        }
        r=zuidagys(l,l+o);
        z=l+o;
        l=l/r;
        z=z/r;
        printf("%d/%d\n",l,z);
    }
}
