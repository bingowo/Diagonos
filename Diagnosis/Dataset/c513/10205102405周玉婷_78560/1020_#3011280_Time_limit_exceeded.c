#include <stdio.h>
#include <string.h>
# include <stdlib.h>

typedef struct{
    char time[18];
    char size[20];
    char name[65];
} file;

int cmp1(const void*pa, const void*pb)//NAME
{
    file a=*(file*)pa;
    file b=*(file*)pb;
    int c;
    c=strcmp(a.name,b.name);
    return c>0?1:-1;
}


int cmp2(const void*pa, const void*pb)//TIME
{
    file a=*(file*)pa;
    file b=*(file*)pb;
    int c;
    c=strcmp(a.time,b.time);
    if(c==0) return cmp1(pa,pb);
    else  return c>0?1:-1;
}

int cmp3(const void*pa, const void*pb)//SIZE
{
    file a=*(file*)pa;
    file b=*(file*)pb;
    int c;
    c=strcmp(a.size,b.size);
    if(c==0) return cmp1(pa,pb);
    else  return c>0?1:-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
       file *p=(file*)malloc(sizeof(file)*n);
       char temp[150];
       for(int i=0; i<n; i++)//input
       {
           scanf("%s %s %s",p[i].time, p[i].size, p[i].name);
       }   
       char order[12];
       scanf("%s",order);
       char c=order[6];
       switch (c)
       {
           case'N':
           qsort(p,n,sizeof(file),cmp1);
           break;
           case'T':
           qsort(p,n,sizeof(file),cmp2);
           break;
           case'S':
           qsort(p,n,sizeof(file),cmp3);
           break;
       }
       for(int i=0; i<n; i++)
       {
           printf("%s %s %s\n",p[i].time,p[i].size,p[i].name);   
       }
       free(p);
    }
    return 0;
}