#include <stdio.h>
#include <stdlib.h>

 int sushu(int n)
 {
     int l=1,i;
     if(n==1)
        n++;
     if(n==2)
        return 2;
     else
     {
         if(n==3)
            return 3;
         else
         {
             for(;l!=0;n++)
             {
                 l=0;
                 for(i=2;i<=n/2;i++)
                 {
                     if(n%i==0)
                        l=l+1;
                 }
             }
             return (n-1);
         }
     }
 }

int main()
{
    char s[10000]={'\0'};
    int i,k=0;
    int a[1000]={0};
    scanf("%s",s);
    for(i=0;s[i];i++)
    {
        if(s[i]==',');
        else
        {
            a[k]=s[i]-'0';
            for(;s[i+1]!=','&&s[i+1];i++)
                a[k]=10*a[k]+s[i+1]-'0';
            k++;
        }
    }
    long long int n=2,weiquan=1;
    long long int x=0;
    for(i=k-1;i>=0;i--)
    {
        x=a[i]*weiquan+x;
        weiquan=n*weiquan;
        n=sushu(++n);
    }
    printf("%lld",x);
}