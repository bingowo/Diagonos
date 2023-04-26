#include<stdio.h>
unsigned hi(int N,int R,char str[]);

int main()
{ int N,R,T,str[1000];
  scanf("%d%d%d",&N,&R,&T);
  hi(N,R,str);
  for(;T>0;T--)
   {printf("%d",str);}
 return 0;
}


unsigned hi(int N,int R,char str[])
{ int i=0,j=1,t;
  if(N<0) j=-1;
 do{ if(R<10||N/R<10)
     {str[i++]=N%R+48;}
     else
     {str[i++]=N/R+55;}
     N=N/R;}
while(N);
  if(j==-1) str[i]='-';
   else i--;
  for(;j<i/2;j++)
  {t=str[j];str[j]=str[i-1-j];str[i-j-1]=t;}
  str[i+1];
}
