#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
 int T,i=0,c,t;
 char s[12];
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%s",s);
 c=strlen(s);
  int j=0;
  double z;
for(j=0;j<c;j++)
 {
     if(!isdigit(s[j])&&isdigit(s[j+1])&&isdigit(s[j+2]))
     {
           switch(s[j])
        {case '+':s[j]=s[j+1]+s[j+2];break;
         case '-':s[j]=s[j+1]-s[j+2];break;
         case '*':s[j]=s[j+1]*s[j+2];break;
         case '/':s[j]=s[j+1]/s[j+2];break;
        }
     for(;j<c-3;j++)
         {t=s[j+1];s[j+1]=s[j+3];s[j+3]=t;}
     c=j-3;
     j=0;
     }
 }
 printf("case #%d:\n",i);
 printf("%c",s[j]);
 }
 return 0;
}
