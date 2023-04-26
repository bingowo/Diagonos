#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
   char s[30];
   char a[100]={0};
   a['0']=0;
   a['1']=1;
   a['2']=-1;
   scanf("%s",s);
   char *p=s;
   long long N=0;
   long long t=0,b=1;
   while(*p)
   {
       N=N*3+a[*p++];
       if((*p)=='.') break;
   }
   if((*p)=='.')
   {
       p++;
      while(*p)
      {
          t=t*3+a[*p++];
          b=b*3;
      }

   }
   if(N*t<0)
   {
       if(N<0)
       {N=abs(N)-1;
       t=b-abs(t);
       printf("-%lld %lld %lld",N,t,b);
       return 0;}
       if(N>0)
       {N=abs(N)-1;
       t=b-abs(t);
       printf("%lld %lld %lld",N,t,b);
       return 0;}
   }
   if(t==0) {printf("%lld",N); return 0;}
   else{
    if(N==0){printf("%lld %lld",t,b); return 0;}
   }
   if(N*t>0){ printf("%lld %lld %lld",N,t,b); return 0;}
}
