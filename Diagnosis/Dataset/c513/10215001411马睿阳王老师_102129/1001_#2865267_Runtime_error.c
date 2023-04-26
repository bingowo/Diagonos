#include <stdio.h>

int main()
{
 int N;char s[1000];
 scanf("%d",&N);
 unsigned hi(char s[]);
 printf("%c",hi(s));
 return 0;
}

 unsigned hi(char s[])
 {int N,R;int i=0,j,t;
   do
   {s[i]=N%R;N=N/R;}
   while(N/R<N);
   if(R<10) {s[i]=s[i]+'0';}
   else  s[i]=s[i]+'55';
   for(i=j=0;j<i/2;i++,j--)
   { t=s[i];s[i]=s[j];s[j]=t;}
 }
