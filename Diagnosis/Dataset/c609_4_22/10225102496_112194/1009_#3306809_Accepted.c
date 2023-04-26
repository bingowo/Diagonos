#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int T;int len,sum,num,a;
    char str[150];
    scanf("%d",&T);
    char c=getchar();
    for(int i=0;i<T;i++)
    {
        num=0;
        gets(str);
        len=strlen(str);
        sum=8*len;
        for(int j=0;j<len;j++)
        {
            a=(unsigned char)str[j];
            while(a!=0)
            {
                if(a%2==1) num++;
                a/=2;
            }
        }
        printf("%d/%d\n",num/gcd(num,sum),sum/gcd(num,sum));
    }
    return 0;
}