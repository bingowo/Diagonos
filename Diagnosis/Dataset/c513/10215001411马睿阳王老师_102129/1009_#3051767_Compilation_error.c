#include<stdio.h>

int max(int m,int n)
{
    if(m%n==0) return n;
    else if(n%m==0) return m;
    else if(m>n) return max(n,m%n);
    else if(m<n) return max(m,n%m);
}//此方法只针对于正数，负数需转化

int main()
{
    int n,i=0,j=0,h=0,g=0,m=0,b=1;
    char s[121];
    scanf("%d",&n);
    gets(s);
    for(i=0;i<n;i++)
    {
        gets(s);
        int sum=0;
        for(j=0;s[j]!='\0';j++)
        {
            for(h=0;h<8;h++)
            {
                if(s[j]&b) //用&直接就是二进制，不用转化
                {
                    sum++;
                    s[j]>>=1;//等号不能忘记
                }
                else s[j]>>=1;

            }
        }
            g=j*8;
            m=max(sum,g);
            sum/=m;
            g/=m;
            printf("%d/%d\n",sum,g);
        for(h=0;h<j;h++) s[h]='\0';/这一步也不需要，gets（有终止信号的数组）可以直接覆盖

    }
    return 0;
}
