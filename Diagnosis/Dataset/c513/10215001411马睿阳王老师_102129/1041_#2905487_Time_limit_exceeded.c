#include<stdio.h>
#include<string.h>
int main()
{
 char s[100];
 int count=1,x=1;
 scanf("%s",s);
  int j=1;
 for(j=1;;j++)
{ if(s[j]!=s[j-1])
   {count++;}
  else
    { if(x<count) {x=count;count=1;}
      else {x=x;count=1;}
    }
  j++;
 }
 printf("%d",x);
 return 0;
}
