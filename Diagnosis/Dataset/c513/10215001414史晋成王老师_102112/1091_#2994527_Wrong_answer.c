#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int l,i=0,j,n,m,t,k=0,flag1,flag2;
  char s1[1000]={0},s2[1000]={0},a[1000]={0},b[1000]={0},c[1000]={0},d[1000]={0},str[1000]={0};
  scanf("%s %d",str,&n);
  if(str[0]=='0' && str[1]=='\0')
  { printf("0"); } 
  int start = 0; 
  int rSig = 1, iSig = 1; 
  if(str[0]=='-')
  { start = 1; rSig = -1; } 
  long long tmp[1000]={0};
  while(str[start]!='+' && str[start]!='-' && str[start]!='\0' && str[start]!='i') 
  {tmp[i++]=str[start++] - 48; }
  if(str[start]=='i')
  { if(tmp[0]==0) {b[0]=1;i=1;} 
    else 
     for(j=0;j<i;j++)
     b[j]=tmp[j]; 
     for(t=0;t<i;t++)
     printf("%d",b[t]);
  } 
  else{
       for(j=0;j<i;j++)
       a[j]=tmp[j];
  if(str[start]=='-') iSig = -1; start++; memset(tmp,0,sizeof(tmp)); 
  while(str[start]!='\0' && str[start]!='i') 
  tmp[k++]=str[start++]-48;
  if(str[start]=='i')
  { if(tmp[0]==0) {b[0]=1;k=1;} 
  else 
    for(j=0;j<k;j++)
    b[j]=tmp[j]; }  
    for(t=0;t<i;t++)
    printf("%d",a[t]);
    printf(" ");
    for(t=0;t<k;t++)
    printf("%d",b[t]);
  }
}