#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
           q=*a>='a'?*a-32:*a;
           w=*b>='a'?*b-32:*b;
           if(s1[q-'A']>s1[w-'A']) return -1;
           else if(s1[q-'A']<s1[w-'A']) return 1;
           else return *b-*a;
       }
       qsort(s2,strlen(s2),sizeof(s2[0]),cmp);
       printf("case #%d:\n",i);
       printf("%s\n",s2);
   }
}
