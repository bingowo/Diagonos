#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
   char s[100];
   scanf("%s",s);
   char a;
   for(int i=0;s[i];i++)
   {
       if(isalpha(s[i])) a=s[i];
   }
   double left=0,right=0;
   char s1[10];
   int num=0;
   int j=0;
   int flag=1;
   while(s[j])
   {
       if(s[j]=='-') flag=-1;
       if(s[j]=='+') flag=1;
       if(isalnum(s[j]))
       {
           memset(s1,0,sizeof(char)*10);
           while(isalnum(s[j]))
           {
               s1[num++]=s[j];
               j++;
           }
           if(s[j]==a)
           {
               double m=0;
               for(int k=0;s1[k];k++)
               {
                   m=m*10+s1[k]-'0';
               }
               left+=m*flag;
               j++;
           }
           else if(s[j]=='-'&&s[j]=='+')
           {
               double m=0;
               for(int k=0;s1[k];k++)
               {
                   m=m*10+s1[k]-'0';
               }
               right+=m*flag;
           }
           else j++;
       }
   }
   printf("%c=%.3f\n",a,right/left);
}
