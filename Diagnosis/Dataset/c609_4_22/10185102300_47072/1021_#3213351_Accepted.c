#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  S[27];
int ord(char c) {  int r; for (r=0;toupper(c)!=S[r];r++); return r; }
int cmp(const void* e1,const void* e2)
{  char *s1=(char*)e1,*s2=(char*)e2;
   while (*s1&&*s2)
        if (ord(*s1)>ord(*s2)) return 1;
        else if (ord(*s1)<ord(*s2)) return -1;
        else s1++,s2++;
   if (*s1) return 1; else if (*s2) return -1; else return 0;
 }
int main()
{ char  t[100][21];
   while (scanf("%s",S)!=EOF)
   {  int n=0,i; do scanf("%s",t+n++); while (getchar()!='\n');
      qsort(t,n,sizeof(t[0]),cmp);
      for(i=0;i<n;i++) printf("%s%c",t[i],i<n-1?' ':'\n');
   }
   
   return 0;
}