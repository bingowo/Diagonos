#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{  char s[1000];
  int j,n,m,k,h,co[1100];
  scanf("%s",s);
  while (*s)
   {  int sign=1,a=0,i=0;
      if (*s=='+' ) s++; 
      else if (*s=='-') sign=-1,s++;
      while (isdigit(*s)) {  a=a*10+*s-'0'; s++; }
      if (a==0) a=1;
      if (*s!='x') { co[0]=a*sign; return; } else s++;
      if (*s=='^') s++;
      while (isdigit(*s)) {  i=i*10+*s-'0'; s++; }
      if (i==0) i=1;
      co[i]=a*sign;
   }
   for(j=0;j<3;j++)
   printf("%d ",j);
   
 }