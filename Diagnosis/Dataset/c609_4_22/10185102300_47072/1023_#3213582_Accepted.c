#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {  char s[20];   int y,m,d; } Date;

int cmp(const void* e1,const void* e2)
{  Date *pday1=(Date*)e1,*pday2=(Date*)e2;int delta;
    if (delta=pday1->y -pday2->y) return delta;
    if (delta=pday1->m -pday2->m) return delta;
    if (delta=pday1->d -pday2->d) return delta;
    return 0;
 }
int m2i(char *s)
{  static char * month[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
                                          "mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
                                          "muan", "pax", "koyab", "cumhu","uayet"};
    int i;  for (i=0;strcmp(s,month[i]);i++); return i;
}
void parse(Date *x)
{  int i=0,j=0; char s[20]; x->d=0;
    while (x->s[i]!='.') x->d=x->d*10+x->s[i++]-'0';
    i+=2;
    while (x->s[i]!=' ') s[j++]=x->s[i++];
    s[j++]=0; i++;
    x->m= m2i(s);
    x->y=0;
    while (isdigit(x->s[i])) x->y=x->y*10+x->s[i++]-'0';
}

int main()
{   int I,T;
     for(scanf("%d",&T),I=0;I<T;I++)
     {    int i,n; Date a[10000];
           printf("case #%d:\n",I);
           scanf("%d\n",&n);
           for  (i=0;i<n;i++)  fgets((a+i)->s,20,stdin),parse(a+i);
           qsort(a,n,sizeof(a[0]),cmp);
           for  (i=0;i<n;i++)  printf("%s", (a+i)->s);
     }

    return 0;
}