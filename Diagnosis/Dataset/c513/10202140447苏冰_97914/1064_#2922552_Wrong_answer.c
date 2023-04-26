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
   char x[110][20];
   char c;
   for(int cas=0;cas<T;cas++)
   {
       int i=0;
       for(i=0;;i++)
       {
           scanf("%s",x[i]);
           c=getchar();
           if(c=='\n') break;
       }
       i++;
       for(int j=0,p=0,q=0;j<i;j++)
       {
           if(x[j][0]=='+' || x[j][0]=='-' || x[j][0]=='*' ||x[j][0]=='/')
           {
               s[p]=x[j][0];p++;
           }
           else
           {
               b[q]=atof(x[j]);q++;
           }
           if(j==i-1) s[p]='\0';
       }
       double ans=b[0];
       for(int j=strlen(s)-1,k=1;j>=0;j--,k++)
       {
           if(s[j]=='+') ans=ans+b[k];
           else if(s[j]=='-') ans=ans-b[k];
           else if(s[j]=='*') ans=ans*b[k];
           else if(s[j]=='/') ans=ans/b[k];
       }
       printf("case #%d:\n",cas);
       printf("%.6f\n",ans);
   }
    return 0;
}
