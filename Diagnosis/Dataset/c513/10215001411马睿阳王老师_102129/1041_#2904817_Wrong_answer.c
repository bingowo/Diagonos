#include<stdio.h>
#include<string.h>
int main()
{
 char s[52];
 int j=1,count=1,x=1;
  scanf("%c",&s[0]);
 while(scanf("%s",s)!=EOF)



 {if(s[j]!=s[j-1])
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
