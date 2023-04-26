#include<stdio.h>


#define N 121
int max(int m,int n)
{
    if(m%n==0)return n;
    else if(n%m==0)return m;
    else if(m>n)return max(n,m%n);
    else if(n>m)return max(m,n%m);
    
}//记住这个写法只针对于正整数，后续如果有负数需要转化一下！！

int main()
{
    int i,n,sum,d=0,x,b=1,j=0,m=0,h=0,g=0;
    char s[N];
    scanf("%d",&n);
    gets(s);
    for(i=0;i<n;i++)
    {
        gets(s);//gets可以读进有空格的字符，而scanf到空格会停止。
        sum=0;
        for(x=0;s[x]!='\0';x++)
           {
               for(h=0;h<8;h++)
               {
                   if(s[x]&b)d++,s[x]>>=1;
                   else s[x]>>=1;
               }//计算每个字符二进制1的个数
                sum=sum+d;
                d=0;
           }
           g=x*8;
           m=max(sum,x*8);
           sum=sum/m;
           x=x*8/m;
        printf("%d/%d\n",sum,x);
    }
    for(j=0;j<g/8;j++)s[j]='\0';//这一步也不需要，gets（有终止信号的数组）可以直接覆盖
    return 0;}