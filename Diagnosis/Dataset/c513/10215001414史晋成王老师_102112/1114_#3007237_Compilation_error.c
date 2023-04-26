#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{  char s[1000];
  int j,n,m,k,h,co[1100],a1,c1,a2,c2,flag;
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
   flag=0;
  for(a1=1;a1<=co[2];a1++)
  { if(co[2]%a1!=0) continue;
    else if(co[2]/a1<a1) break;
    else
    { a2=co[2]/a1;
      for(c1=1;c1<abs(co[0]);c1++)
      {if(co[0]%c1!=0) continue;
        c2=co[0]/c1;
          if(c2*a1+a2*c1==co[i]) break;
      }
      if(c2*a1+a2*c1==co[i]) {flag=1;break;}
    }
      
  }
  
  if(a1==a2&&c2<c1) {f=c2;c2=c1;c1=f;}
  if(flag==0) printf("No Answer!")
  else printf("%d %d %d %d",a1,c1,a2,c2);
   
 }