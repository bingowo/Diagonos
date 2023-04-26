#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {char*p;int cnt;}DNA;
int cmp2(const void*a,const void*b)
{
    DNA d1,d2;
    d1=*((DNA*)a);
    d2=*((DNA*)b);
    if(d1.cnt!=d2.cnt) return d1.cnt-d2.cnt;
    else return strcmp(d1.p,d2.p);
}

int cmp1(const void*a,const void*b)
{
    return strcmp(*(char**)a,*(char**)b);
}
int main()
{  char s[21],*p;
   int n,i,len;
   char** d;
   scanf("%d\n",&n);
   d=(char**)malloc(n*sizeof(char*));
   for(i=0;i<n;i++)
   {
       scanf("%s",s);
       len=strlen(s);
       p=(char*)malloc(len+1);
       strcpy(p,s);
       *(d+i)=p;
   }
   qsort(d,n,sizeof(d[0]),cmp1);
   typedef struct {char*p;int cnt;}DNA;
   DNA* dna;
   int m=0;
   dna=(DNA*)malloc(n*sizeof(DNA));
   dna[0].p=d[0];
   dna[0].cnt=1;
   
   for(i=1;i<n;i++)
   {
       if(strcmp(d[i],d[i-1])==0)
         dna[m].cnt++;
       else 
       {
           m++;
           dna[m].p=d[i];
           dna[m].cnt=1;
       }
   }
   qsort(dna,m+1,sizeof(dna[0]),cmp2);
   
   for(i=0;i<=m;i++)
    printf("%s\n",dna[i].p);
   free(dna);
   for(i=0;i<n;i++) free(d[i]);
   free(d);
}