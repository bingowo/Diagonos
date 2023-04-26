#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    long long int ans;
    char s[20];
}Thr;
int cmp(const void *p1,const void *p2)
{
    Thr* a=p1;
    Thr* b=p2;
    if(a->ans<b->ans) return -1;
    else if(a->ans>b->ans) return 1;
    else return strcmp(a->s,b->s);
}
int main()
{
   int N;
   scanf("%d",&N);
   Thr q[20000];
   for(int i=0;i<N;i++)
   {
       scanf("%s",q[i].s);
       int a[128];
       for (int j=0;j<128;j++) a[j]=-1;
       char *p=q[i].s;
       a[*p]=1;
       int num=0;
       int d=0;
       while(*++p)
       {
           if(a[*p]==-1)
           {
               a[*p]=d;
               num++;
               if(d==0) d=2;
               else d++;
           }
       }
        if(num<2) num=2;
        p=q[i].s;
       while(*p!=0)
       {
           q[i].ans=q[i].ans*num+a[*(p++)];
       }
   }
   qsort(q,N,sizeof(Thr),cmp);
   for(int j=0;j<N;j++)
   {
       printf("%s\n",q[j].s);
   }
}
