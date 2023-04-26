#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *domain(char*s)
{  while(*s!='@') s++;  return s+1; }

int cmp(const void* e1,const void* e2)
{  char *s1=*(char**)e1,*s2=*(char**)e2;int delta;
    if (delta=strcmp(domain(s1),domain(s2))) return delta;
    return strcmp(s2,s1);
 }


int main()
{ int i,n; char *t[100],*s=(char*)malloc(sizeof(char)*1000001); scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%s",s),strcpy(t[i]=(char*)malloc(sizeof(char)*(strlen(s)+1)),s);
   qsort(t,n,sizeof(t[0]),cmp);
   for(i=0;i<n;i++) printf("%s\n",t[i]);

   free(s); for(i=0;i<n;i++) free(t[i]);
   return 0;
}

