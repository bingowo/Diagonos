#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);
    if(aa>=bb) return -1;
    else if(aa<bb) return 1;

}

int main()
{
   int re,len,i,k;
   int co[60];
   memset(co,0,60*sizeof(int));
   char s[100];
   memset(s,0,sizeof(char)*100);
   gets(s);
   len=strlen(s);
   for(i=0;i<len;i++)
   {
       if(s[i]!=s[i+1]) co[k]++;
       else {co[k]++;k++;continue;}
   }
   qsort(co,k,sizeof(int),cmp);
   re=co[0];
   printf("%d",re);
   return 0;

}
