#include<stdio.h>
#include<string.h>
int main()
{
 char s[100];
 int count=1,x=1;
 scanf("%s",s);
 int j=1,c;
 c=strlen(s);
 for(j=1;j<=c;j++)
{if(c==1) x=1;
 else{
     if(s[j]!=s[j-1])
   {count++;
    if(x<count) x=count;
   }
  else
    { if(x<count) {x=count;count=1;}
      
    }
  j++;
  if(j=c-1) break;
 }
 }
 printf("%d",x);
 return 0;
}
