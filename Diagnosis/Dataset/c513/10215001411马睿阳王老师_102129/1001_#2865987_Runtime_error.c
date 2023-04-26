#include <stdio.h>
unsigned hi(int N,int R,int s[1000]);

int main()
{ int N,R,T;
 int s[1000];
 scanf("%d%d%d",&N,&R,&T);
  hi( N, R, s[1000]);
 do
 {printf("%d",s);T--;}
 while(T>0);
 return 0;
}

 unsigned hi(int N,int R,int s[1000])
 { int i,j=0,t,a;
   if(N<0) {N=-N;}
   do
   {s[i]=N%R;a=N/R;N=a;}
   while(a<N);
   if(R<10) {s[i++]=s[i]+'48';}
   else  s[i++]=s[i]+'55';
   for(i=j=0;j<i/2;i++,j--)
   { t=s[i];s[i]=s[j];s[j]=t;}
 }


