#include<stdio.h>
#include<string.h>
unsigned hi(int N,int R,char str[]);
int main()
{ int T,i;
  scanf("%d",&T);
  for(i=0;i<T;i++)
  {int N,R;char str[1000];
   scanf("%d%d",&N,&R);
   hi(N,R,str);
   printf("%c",str);}
 return 0;
}
unsigned hi(int N,int R,char str[])
{ int i=0,j=1,t,n;
  if(N<0) {N=-N; j=-1;}
 do{ if(R<10||N/R<10)
     {str[i++]=N%R+'0';}
     else
     {str[i++]=N%R+'A';}
     N=N/R;}
while(N);
  if(j==-1) str[i]='-';
   else i--;
  for(n=0;n<i/2;n++)
  {t=str[n];str[n]=str[i-n];str[i-n]=t;}
  str[i+1]=0;
}
