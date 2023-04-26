#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
   int n,m,i,j;
   char  c,*p=(char*)malloc(1000001),*p0=p;
   while((c=getchar())!='\n')
   {
       if(strchr(p0,c)==NULL)*(p++)=c;
   }
   *p=0;printf("%s",p0);
   free(p0);
}
