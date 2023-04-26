#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int l,i=0,j,n,m,t,k=0,x,y;
  int s1[1000]={0},s2[1000]={0},c=0,d=0;
  char str[1000]={0};
  scanf("%s %d",str,&n);
  if(str[0]=='0' && str[1]=='\0')
  { printf("0"); } 
  int start = 0; 
  int rSig = 1, iSig = 1; 
  if(str[0]=='-')
  { start = 1; rSig = -1; } 
  long long tmp=0,a=0,b=0; 
  while(str[start]!='+' && str[start]!='-' && str[start]!='\0' && str[start]!='i') 
  tmp = tmp*10 + str[start++] - 48; 
  if(str[start]=='i')
  { if(!tmp) b=1*rSig; else b= tmp*rSig; } 
  else{ a=tmp*rSig; 
  if(str[start]=='-') iSig = -1; start++; tmp = 0; 
  while(str[start]!='\0' && str[start]!='i') 
  tmp = tmp*10 + str[start++] - 48;
  if(str[start]=='i')
  { if(!tmp) b= 1*iSig; else b= tmp*iSig; } }
  long long int r1=1,r2=b;
  for(i=1;i<n;i++)
  { r1=r1*a-r2*b;
      r2=r2*a+r1*b;
  }
  if(r1==0) printf("%lldi",r2);
  else if(r2==0) printf("%lld",r1);
  else if(r2==1) printf("%lld+i",r1);
  else if(r2==-1) printf("%lld-i",r1);
  else if(r2>0)  printf("%lld+%lldi",r1,r2);
  else if(r2<0)  printf("%lld-%lldi",r1,r2);
}