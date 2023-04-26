#include<stdio.h>
#include<string.h>
int main
{
 char s[100];
 int i=0;
 while(s)
 {scanf("%s",s);
  i++;
 }
 int j=1,count=0,x=1;
 for(j=1;j<strlen(s);j++)
 {if(s[j]!=s[j-1])
   {count++;
   j++;}
  else
    { if(x<count) {x=count;count=0;j++;}
      else {x=x;count=0;j++;}
    }
 }
 printf("%d",x);
 return 0;
}
