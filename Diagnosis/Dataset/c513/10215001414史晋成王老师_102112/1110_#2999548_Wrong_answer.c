#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ char str[1000],str1[1000];
  int i,j,n,m,start=0,tmp,a,b,rSig,iSig,t1,t2;
  scanf("%s",str);
  rSig=1;iSig=1;tmp=0;t1=0;t2=0;
  while(str[start]!=0)
  {
    if(str[start]=='-')
  { start++; rSig = -1; } 
  while(str[start]!='+' && str[start]!='-' && str[start]!='\0' &&!isalpha(str[start])) 
  tmp = tmp*10 + str[start++] - 48; 
  if(isalpha(str[start]))
  { if(!tmp) b=1*rSig; else b= tmp*rSig; 
    t1+=b;start++;} 
  else{ a=tmp*rSig; 
   t2+=a;start++;} 
   if(str[start]=='=') break;
  } 
  printf("%d %d",t1,t2);
    
}