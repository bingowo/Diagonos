#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
double tab[26];
int cmp(const void*a,const void*b)
{
    char pa=*(char*)a-'a',pb=*(char*)b-'a';
    if(pa<0){pa+='a'-'A';if(pa==pb)return 1;}
    if(pb<0){pb+='a'-'A';if(pa==pb)return -1;}
     if(fabs(tab[pa]-tab[pb])<=0.01){return pa-pb;}
    else return tab[pa]<tab[pb]?1:-1;
}
int main()
{
   int i,n;
   scanf("%d\n",&n);
   for(i=0;i<n;i++)
   {
       int j;
       for(j=0;j<26;j++)scanf("%lf",&tab[j]);
       char s[101];
       scanf("%s",s);
       qsort(s,strlen(s),sizeof(s[0]),cmp);
       printf("case #%d:\n%s\n",i,s);
       
   }
}
