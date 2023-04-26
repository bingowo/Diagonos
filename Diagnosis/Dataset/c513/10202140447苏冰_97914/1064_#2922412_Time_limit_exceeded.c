#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
   int T;
   scanf("%d",&T);
   char s[110];
   double b[110];
   char x[10];
   char c;int k;int flag=1;getchar();
   for(int cas=0;cas<T;cas++)
   {
       k=0;flag=1;
       while(flag)
       {
           c=getchar();
           if(c=='+' || c=='-' || c=='*' || c=='/')
           {
               s[k]=c;k++;
           }
           else if(isdigit(c))
           {
               s[k]='\0';
               int j=0;x[j]=c;
               while((c=getchar())!=' ')
               {
                   j++;x[j]=c;
               }
               x[++j]='\0';
               flag=0;
           }
       }
       double m;
       if(strchr(x,'.')) m=atof(x);
       else m=atoi(x);
       b[0]=m;
       k=1;
       while(1)
       {
           scanf("%lf%c",&b[k],&c);
           k++;
           if(c=='\n') break;
       }
       double ans=b[0];
       for(int i=strlen(s)-1,j=1;i>=0;i--,j++)
       {
           if(s[i]=='+') ans=ans+b[j];
           else if(s[i]=='-') ans=ans-b[j];
           else if(s[i]=='*') ans=ans*b[j];
           else if(s[i]=='/') ans=ans/b[j];
       }
       printf("case #%d:\n",cas);
       printf("%.6f\n",ans);
   }
    return 0;
}
