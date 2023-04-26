#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
   int n,m,i,j,max=0;
   char  *p=(char*)malloc(1000001),*p0=p,*p1=p,*ans=(char*)malloc(1000001);
   memset(p,0,1000001);
   scanf("%s",p);
   while(*p1)
   {
       while(memchr(p,*p1,p1-p)==NULL&&*p1)p1++;

       if(p1-p>max){strncpy(ans,p,p1-p);*(ans+(p1-p))=0;max=p1-p;}
       p++;
       while(*p!=*p1&&p<=p1)p++;

   }
   printf("%s",ans);
   free(p0);free(ans);
}
