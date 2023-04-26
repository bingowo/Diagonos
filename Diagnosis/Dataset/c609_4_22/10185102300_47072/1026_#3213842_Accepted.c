#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {  char s[ 21]; int n; } TYPE;

int find(char *s,int n, char c)
{  int i; for(i=0;i<n;i++) if(s[i]==c) return 1;  return 0; }
int digits(const char* s)
{  int i=0,r=0;
    while(s[i]) { if (!find(s,i,s[i])) r++; i++; }
    return r;
}


int cmp(const void* e1,const void* e2)
{  TYPE *p1=(TYPE*)e1,*p2=(TYPE*)e2; int delta;
     if (delta=p2->n-p1->n) return delta;
     return strcmp(p1->s,p2->s);
}



int main()
{  int I,T;
    for(scanf("%d",&T),I=0;I<T;I++)
    {   int i,n; TYPE a[100];
         printf("case #%d:\n",I); scanf("%d",&n);
         for  (i=0;i<n;i++)  scanf("%s",a[i].s),a[i].n=digits(a[i].s);
         qsort(a,n,sizeof(a[0]),cmp);
         for  (i=0;i<n;i++)  printf("%s\n", a[i].s);
    }

    return 0;
}