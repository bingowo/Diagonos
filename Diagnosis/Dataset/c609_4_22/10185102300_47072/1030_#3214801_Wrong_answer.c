#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double f[26];
double freq(char c) { return f[toupper(c)-'A']; }

int cmp(const void* e1,const void* e2)
{  char c1=*(char*)e1,c2=*(char*)e2; int delta;
    if (delta = freq(c2)-freq(c1)) return delta;
    if (delta = toupper(c1)-toupper(c2)) return  delta;
    return c2-c1;
}

int main()
{  int I,T;
    for(scanf("%d",&T),I=0;I<T;I++)
    {   int i; char s[101];
         printf("case #%d:\n",I);
         for  (i=0;i<26;i++)  scanf("%lf",f+i);
         scanf("%s",s);  
         qsort(s,strlen(s),sizeof(s[0]),cmp);
         printf("%s\n", s);
    }

    return 0;
}