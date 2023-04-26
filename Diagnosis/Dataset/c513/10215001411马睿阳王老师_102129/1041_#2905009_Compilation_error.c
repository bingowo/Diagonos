#include<stdio.h>
#include<string.h>
int main()
{
 char str[52],s;
 int j=0,count=1,x=1;
 while((str=getchar())!='\n')
 s[j++]=str;
  
 while(scanf("%s",s)!=EOF)



 {
     j=1;
     if(s[j]!=s[j-1])
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
