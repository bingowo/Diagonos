#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
     char s[20];
     long long va; 
}digi;
long long tran(char*s)
{  char *p=s;
    int d=0,n=1,i;
    long long sum=0;
    int al[128];
    for(i=0;i<128;i++) al[i]=-1;
    al[*p]=1;
    while(*++p)
    {   if(al[*p]==-1)
     {  al[*p]=d;
        d=d?d+1:2;
      n++;//有几个不同符号取多少进制 
  }
 }
 if(n<2) n=2;//最小为二进制
 p=s; //key 
 while(*p) sum=sum*n+al[*p++];
 return sum;
}
int cmp(const void*a,const void*b)
{    digi aa=*(digi*)a;
  digi bb=*(digi*)b;
  if(aa.va!=bb.va)
  {  if(aa.va>bb.va) return 1;
   else return -1;
  }
 else 
  return strcmp(aa.s,bb.s);
 
}
int main()
{    digi f[10002];
 int n,i;
 scanf("%d\n",&n);
 for(i=0;i<n;i++)
 {   gets(f[i].s);
  f[i].va=tran(f[i].s);
  } 
 qsort(f,n,sizeof(f[0]),cmp);
 for(i=0;i<n;i++) printf("%s\n",f[i].s);
 return 0;
}