#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{  char s[1000];
  int j,n,m,k,h,co[1100];
  scanf("%s",s);
  k=0;
  while (s[k])
   {  int sign=1,a=0,i=0;
      if (s[k]=='+' ) k++; 
      else if (s[k]=='-') {sign=-1;k++;}
      while (isdigit(s[k])) {  a=a*10+s[k]-'0'; k++; }
      if (a==0) a=1;
      if (s[k]!='x') { co[0]=a*sign; break; } else k++;
      if (s[k]=='^') k++;
      while (isdigit(s[k])) {  i=i*10+s[k]-'0'; k++; }
      if (i==0) i=1;
      co[i]=a*sign;
   }
   for(j=1;j<3;j++)
   printf("%d ",co[j]);
   
 }