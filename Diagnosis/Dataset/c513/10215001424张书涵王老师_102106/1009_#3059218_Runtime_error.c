#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gongyinshu(int a,int b)
{
    int m,n,yu;
    for(m=b,n=a;m%n;)
    {
        yu=m%n;
        m=n;
        n=yu;
    }
    return n;
}

int main()
{
    int n;
    scanf("%d ",&n);
    int i;
    for(i=0;i<n;i++)
    {
        char s1[120]={0};
        gets(s1);
        int len,zero=0,one=0,j,num,total,both;
        len=strlen(s1);
        for(j=0;j<len;j++)
        {
            num=(unsigned char)s1[j];
            while(num)
            {
                if(num%2==1)
                    one++;
                else
                    zero++;
                num=num/2;
            }
        }
        total=8*len;
        both=gongyinshu(one,total);
        one=one/both;
        total=total/both;
        printf("%d/%d\n",one,total);
    }
}

