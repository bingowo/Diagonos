#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int f(char s[])
{
   int a[123],sum=0,i,j;
   int b[61];
   for(i=0;i<strlen(s)&&(s[i]=='1'||s[i]=='0');i++)
   {
       sum=sum*2+s[i]-'0';
   }
   if(i==strlen(s)) return sum;
   sum=0;
   for(i=0;i<123;i++)
        a[i]=-1;
   for(j=0,i=0;j<strlen(s);j++)
   {
      int t=s[j]-0;
      if(a[t]==-1)
      {
          if(j==0) a[t]=1,b[j]=1;
          if(j==1) a[t]=0,b[j]=0;
          else b[j]=i,a[t]=i;
          i++;
       }
       else b[j]=a[t];
   }
   for(j=0;j<strlen(s);j++)
   {
       sum=sum*i+b[j];
   }
   return sum;
}

int main()
{
    int T;
    char s[61];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
       scanf("%s",s);
       printf("case #%d:\n%d\n",i,f(s));
    }
    return 0;
}
