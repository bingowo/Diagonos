#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
   int n,m,i,j;
   char  c=getchar(),*p=(char*)malloc(1000001),*p0=p,*ans=(char*)malloc(1000001),*ans0=ans;
   do
   {
       *(p++)=c;
       do{*(p++)=c;c=getchar();}while(strchr(p0,c)==NULL&&c!='\n');
       *(p)=0;
       if(strlen(p0)>strlen(ans))strcpy(ans,p0);
       p=p0;
       memset(p0,0,1000001);
   }while(c!='\n');
   printf("%s",ans+1);
   free(p0);free(ans0);
}
