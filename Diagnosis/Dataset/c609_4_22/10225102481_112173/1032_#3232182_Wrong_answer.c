#include <stdio.h>
#include <stdlib.h>

int main()
{
   char a[100];
   int i=1,j=0,k=0;
   gets(a);
   puts(a);
   for(;a[j]!='\0';j++)
   {
       if(a[j]==a[j+1]||a[j+1]=='\0')
       {
           if(k<i)k=i;
           i=1;
       }
       else i++;
   }
   printf("%d",k);
   return 0;
}
