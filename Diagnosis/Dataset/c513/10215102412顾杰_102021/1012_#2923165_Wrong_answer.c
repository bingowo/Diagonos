#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
   char s[1000],sr[1000],si[1000],ans[1000],*p=s+1;
   memset(ans,0,1000);
   long long a,b,qr,qi,i=0,r;
   scanf("%s",s);
   while(*p!='+'&&*p!='-'&&*p)p++;
   strncpy(sr,s,p-s);sr[p-s]=0;
   if(*(p+1)=='i')*(p+1)='1';
   strcpy(si,p);
   a=atoll(sr);b=atoll(si);
   if(*(p-1)=='i'){if(*(p-2)=='-')a=-1;b=a;a=0;}
   //printf("%lld@%lld\n",a,b);
   do
   {
       if(abs(a)%2+abs(b)%2==1)r=1;
       else r=0;
       ans[i++]=r+'0';
       qr=(b-a+r)/2;
       qi=(-b-a+r)/2;
       a=qr;b=qi;
   }while(a||b);
   for(p=ans+strlen(ans)-1;p>=ans;p--)printf("%c",*p);

}
