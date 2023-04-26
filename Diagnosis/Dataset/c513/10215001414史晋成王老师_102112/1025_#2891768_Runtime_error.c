#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct word {
    int count;
    char id[200];
};
int cmp(const void*a,const void*b)
{ struct word d1,d2;
d1=*((struct word*)a);
d2=*((struct word*)b);
if (d1.count!=d2.count) return d2.count-d1.count;
else return 1;
}

int main()
{int T,n,i,j,t,o,k; struct word s[21];
for(i=0;i<21;i++)
s[i].count=0;
 scanf("%d\n",&T);
 for(i=0;i<T;i++)
 {scanf("%d\n",&n);
 for(j=0;j<n;j++)
 {scanf("%s",s[j].id);
   }
   printf("case #%d:\n",i);
   qsort(s,n,sizeof(s[0]),cmp);
   for(k=0;k<n;k++)
   { int o=0;
        printf("\n");
   }
 }
     return 0;
 }