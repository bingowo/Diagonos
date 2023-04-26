#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ char str[1000],str1[1000],s;
  int i,j,n,m,start=0,tmp,a,b,rSig,iSig,t1,t2,c1,c2;
  double f,f1,f2;
  scanf("%s",str);
  rSig=1;iSig=1;tmp=0;t1=0;t2=0;
  if(str[0]=='-')
  { start++; rSig = -1; } 
  while(str[start]!=0)
  { 
  while(str[start]!='+' && str[start]!='-' && str[start]!='\0' &&!isalpha(str[start])&&str[start]!='=') 
  tmp = tmp*10 + str[start++] - 48; 
  if(isalpha(str[start]))
  { s=str[start];
  if(!tmp) b=1*rSig; else b= tmp*rSig; 
    t1+=b;} 
  else{ a=tmp*rSig; 
   t2+=a;}
   tmp=0;
   rSig=1;iSig=1;
   if(str[start]=='=') {start++;break;}
   else if(str[start]=='-')
  { start++; rSig = -1; }
  else {start++;}
  } 
    rSig=1;iSig=1;tmp=0;c1=0;c2=0;a=0;b=0;
   if(str[start]=='-')
  { start++; rSig = -1; } 
  while(str[start]!='\0')
  { 
  while(str[start]!='+' && str[start]!='-' && str[start]!='\0' &&!isalpha(str[start])&&str[start]!='=') 
  tmp = tmp*10 + str[start++] - 48; 
  if(isalpha(str[start]))
  { s=str[start];
      if(!tmp) b=1*rSig; else b= tmp*rSig; 
    c1+=b;} 
  else{ a=tmp*rSig; 
   c2+=a;}
   tmp=0;
   rSig=1;iSig=1;
   if(str[start]==0) break;
  if(str[start]=='-')
  { start++; rSig = -1; }
  else {start++;}
  }
  f1=t1-c1;
  f2=c2-t2;
  printf("%c=%.3lf",s,f2/f1);
    
}