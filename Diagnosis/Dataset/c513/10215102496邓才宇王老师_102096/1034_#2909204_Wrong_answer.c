#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       double s1[27];
       for(int j=0;j<26;j++)
        scanf("%lf",&s1[j]);
       char s2[101];
       scanf("%s",s2);
       int cmp(const void *p1,const void *p2)
       {
           char* a=p1;
           char* b=p2;
           char q,w;
           q=toupper(*a);
           w=toupper(*b);
           if(s1[q-'A']>s1[w-'A']) return -1;
           else if(s1[q-'A']<s1[w-'A']) return 1;
           else if(fabs(s1[q-'A']-s1[w-'A'])<1e-8) return *b-*a;
       }
       qsort(s2,strlen(s2),sizeof(s2[0]),cmp);
       printf("case #%d:\n",i);
       printf("%s\n",s2);
   }
}
