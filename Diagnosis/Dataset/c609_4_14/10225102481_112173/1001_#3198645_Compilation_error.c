#include<stdio.h>
int main()
{
    int a,b,i=0,m,j;
    char s[1000];
    while(scanf("%d %d",&a,&b)!=EOF)
    {if(a<0)
       {printf('-');n=n-2*n;}
     while(a!=0)
     {
       m=n/b;
       s[i]=n%b;
       n=m;
       i++;
     }
     for(j=i;j>0;j--)
     {
         if(s[j]>=10&&s[j]<=b)printf("%c",s[j]+55);
         else printf("%c",s[j]);
     }
    }
}