#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char num[100],f[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};;
    int n,a,b,e;
    n=0;
    scanf("%d %d",&a,&b);
    if(a==0)
        printf("0");
   while(a!=0)
   {
       if(a>0)
       {
           num[n]=f[a%b];
           a=a/b;
       }
       else
       {
           if(a%b==0)
           {
               num[n]=f[0];
               a=a/b;
           }
           else
           {
               num[n]=f[a%b-b];
               a=a/b+1;
           }
       }
       n++;
   }
   for(int i=n-1;i>=0;i--)
   {
       printf("%c",num[i]);
   }
    return 0;
}
