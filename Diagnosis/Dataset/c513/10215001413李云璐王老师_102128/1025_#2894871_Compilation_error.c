#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[101];int count;}TEAM;

TEAM*INPUT(int m)
{ TEAM*p;
  p=(TEAM*)malloc(m*sizeof(TEAM));
  for(int i=0;i<m;i++)
  {
  int a[91]={0};
  scanf("%s\n",p[i].s);
  int len=strlen(p[i].s);
  p[i].count=0;
  for(int l=0;l<len;l++)
  if(a[p[i].s[l]]==0) {a[p[i].s[l]]=1;p[i].count++}
  }
  return p;
}
void sort(TEAM*p,int m)
{
    int compare(const void*a1,const void*a2)
    {
        TEAM a=*(TEAM*)a1;
        TEAM b=*(TEAM*)a2;
        if(a.count!=b.count) return b.count-a.count;
        else return strcmp(a.s,b.s);
    }
    qsort(p,m,sizeof(TEAM),compare);
}
  
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        TEAM*p=NULL;
        p=INPUT(m);
        sort(p,m);
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++)
        printf("%s\n",p[k].s);
    }
    return 0;
}