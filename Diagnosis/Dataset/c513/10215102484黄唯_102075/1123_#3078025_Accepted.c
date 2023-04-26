#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
struct DNA 
{ int cnt; 
char dna[21];
};
int cmp1(const void* a,const void* b)
{ struct DNA *p,*q; p=(struct DNA*)a;q=(struct DNA*)b; 
return strcmp(p->dna,q->dna); }
int cmp2(const void* a,const void* b)
{ struct DNA *p,*q; p=(struct DNA*)a;q=(struct DNA*)b;
if(p->cnt==q->cnt) return strcmp(p->dna,q->dna);
else 
return p->cnt-q->cnt; }
int main() 
{ int n;
scanf("%d",&n);
struct DNA* p=(struct DNA*)malloc(n*sizeof(struct DNA));
int k=0,i; for(i=0;i<n;i++) 
{ scanf("%s",(p+i)->dna); (p+i)->cnt=0; }
qsort(p,n,sizeof(p[0]),cmp1); //按字符串字典序排序 //统计字符串出现的次数，相同字符串第一次出现的cnt值设置为出现次数，其它设置为0
//cnt为0的字符串经过排序后，出现在末尾，不输出 
while(k<n)
{ (p+k)->cnt=1; 
for(i=k+1;i<n;i++)
{ if(strcmp((p+k)->dna,(p+i)->dna)==0)
(p+k)->cnt++; else break; }k=i; }
qsort(p,n,sizeof(p[0]),cmp2); //按照出现次数升序排序，如果相同，则按照字典序升序排 序 
for(i=0;i<n;i++) 
{ if((p+i)->cnt) 
printf("%s\n",(p+i)->dna); }
return 0; 
    
}