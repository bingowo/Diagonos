#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {  char s[12]; int score; } TYPE;


int cmp(const void* e1,const void* e2)
{  TYPE *p1=(TYPE*)e1,*p2=(TYPE*)e2; int delta;
     if (delta=p2->score-p1->score) return delta;
     return strcmp(p1->s,p2->s);
}

int main()
{  int I,T;
    for(scanf("%d",&T),I=0;I<T;I++)
    {   int i,n,m,g,N; int mm[10];TYPE a[500];
         printf("case #%d:\n",I); scanf("%d%d%d",&n,&m,&g);
         for  (i=0;i<m;i++)  scanf("%d",mm+i);
         for  (N=i=0;i<n;i++)
         { int j,d,total; scanf("%s",a[N].s);a[N].score=0;
           for  (scanf("%d",&total),j=0;j<total;j++)
           { scanf("%d",&d);a[N].score+=mm[d-1]; }
            if (a[N].score>=g) N++;
         }

         printf("%d\n", N); qsort(a,N,sizeof(a[0]),cmp);
         for  (i=0;i<N;i++)  printf("%s %d\n", a[i].s,a[i].score);
    }

    return 0;
}