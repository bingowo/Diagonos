#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int re(int n)
{
    int a=n,i=0;
    while(a)
    {
        a/=10;
        i++;
    }
    int l=i-1;
    char *s;
    s=(char*)malloc(i*sizeof(char));
    for(i=l;i>=0;i--)
    {
        s[i]=n%10+'0';
        n/=10;
    }
    for(i=0;i<=l/2;i++)
    {
        if(s[i]!=s[l-i]) break;
    }
    if(i!=l/2+1) return 1;
    else return 0;
}
int main()
{
     int n,i,n1,j,a,sum=0;
     scanf("%d",&n);
     while(re(n))
     {
         sum++;
         i=0;
         a=n;
         while(a)
        {
           a/=10;
           i++;
        }
        int l=i-1;
        int n1=0;
        char *s;
        s=(char*)malloc(i*sizeof(char));
        a=n;
        for(i=l;i>=0;i--)
       {
           s[i]=a%10+'0';
           a/=10;
       }
       n1=0;
       for(i=l;i>=0;i--)
          n1=n1*10+(s[i]-'0');
       n=n+n1;
    }
   printf("%d %d",sum,n);
   return 0;
}
