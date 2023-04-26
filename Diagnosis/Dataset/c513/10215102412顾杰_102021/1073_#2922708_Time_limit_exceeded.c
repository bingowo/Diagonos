#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main()
{
   long long a,b,ans=0,i;
   char s[20],*p;
   scanf("%lld%lld",&a,&b);
   for(i=a;i<=b;i++)
   {
       if(i%9==0)continue;
       else
       {
           sprintf(s,"%lld",i);
           if((p=strchr(s,'9'))!=NULL)
            {
                if(p!=s+strlen(s)-1)
                {
                    p--;
                    (*p)++;
                    p++;
                    while(p<s+strlen(s))*p='0';
                    i=atoll(s)-1;
                }
                continue;}
       }ans++;
   }
   printf("%lld",ans);
   return(0);
}
