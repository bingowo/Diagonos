#include<stdio.h>
unsigned hi(int N,int R,char str[]);

int main()
{ int N,R,T,str[1000];
  scanf("%d",&T);
  scanf("%d%d",&N,&R);
  hi(N,R,str);
  do{printf("%d",str);T--;}
  while(T>0);
  return 0;
}


unsigned hi(int N,int R,char *str)
{ int i;
 if(N<0) {N=-N;str[i++]='-';}
 do{ if(R<10||N/R<10)
     {str[i++]=N%R+48;}
     else
     {str[i++]=N/R+55;}
     N=N/R;}
while(N);
  int j=0,t;
  if(str[0]=='-')
  {j=1;i++;}
  for(;j<i/2;j++)
  {t=str[j];str[j]=str[i-1-j];str[i-j-1]=t;}
}
