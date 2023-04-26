#include <stdio.h>

int main()
{
 int N=4,R=2;char s[1000];
 scanf("%d%d",&N,&R);
 unsigned hi(char s[]);
 printf("%c",hi(s));
 return 0;
}

 unsigned hi(char s[])
 {int N,R;int i,j=0,t,a;
   if(N<0) {N=-N;}
   do
   {s[i]=N%R;a=N/R;N=a;}
   while(a<N);
   if(R<10) {s[i++]=s[i]+'48';}
   else  s[i++]=s[i]+'55';
   for(i=j=0;j<i/2;i++,j--)
   { t=s[i];s[i]=s[j];s[j]=t;}
 }

