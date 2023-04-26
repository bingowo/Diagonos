#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char date[11];
    char time[6];
    int size;
    char name[128];
} file;

int cmp1(const void*pa, const void*pb)//NAME
{
    file a=*(file*)pa;
    file b=*(file*)pb;
    return  strcmp(a.name,b.name);
}


int cmp2(const void*pa, const void*pb)//TIME
{
    file a=*(file*)pa;
    file b=*(file*)pb;
    if(strcmp(a.date,b.date)==0) 
    {
      if(strcmp(a.time,b.time)==0)
      return strcmp(a.name,b.name);
      else return strcmp(a.time,b.time);
    }
    else return strcmp(a.date,b.date);
}

int cmp3(const void*pa, const void*pb)//SIZE
{
    file a=*(file*)pa;
    file b=*(file*)pb;
    if(a.size == b.size) return strcmp(a.name,b.name);
    else  return a.size - b.size;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
       file p[n];
       for(int i=0; i<n; i++)//input
       {
           scanf("%s %s %d %s", p[i].date, p[i].time,&p[i].size, p[i].name);
       }   
       char temp[5],order[5];
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
           printf("%s %s %16d %s\n",p[i].date,p[i].time,p[i].size,p[i].name);   
       }
       printf("\n");
       scanf("%d",&n);
    }
    return 0;
}