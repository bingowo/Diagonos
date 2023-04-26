#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int calculate(char c)
{
    int n = (int)c;
    int ans=0;
    for(int i=1;i<=8;i++)
    {
        ans+=n&1;
        n=n>>1;
    }
    return ans;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
     int n;
     scanf("%d",&n);
     char s[130];
     gets(s);
     for(int i=1;i<=n;i++)
     {
         gets(s);
         int mi=0;
         for(int j=0;j<strlen(s);j++)
         {
             int num=calculate(s[j]);
             mi+=num;
         }
         int mu=strlen(s)*8;
         int go=gcd(mi,mu);
         mi=mi/go;
         mu=mu/go;
         printf("%d/%d\n",mi,mu);
     }
     return 0;
}
