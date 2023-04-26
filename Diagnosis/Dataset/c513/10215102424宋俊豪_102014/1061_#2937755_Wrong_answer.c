#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct{char s[20];int n;}list;
int cmp(const void*a,const void *b)
{
    list *x=(list*)a;
    list *y=(list*)b;
    if(x->n>y->n)
        return 1;
    else if(x->n==y->n)
        return strcmp(x->s,y->s);
    else
        return -1;
}
int read(char s[])
{   int a[128];int i=0,num=0,total=0;
    for(i=0; i<128; i++)
        a[i]=-1;
    int len=strlen(s);
        for (int j=0; j<len; j++)
        {
            if (a[s[j]]==-1)
            {
                if (num==0)
                    a[s[j]]=1;
                else if (num==1)
                    a[s[j]]=0;
                else
                    a[s[j]]=num;
                num++;
            }
        }
        if (num==1)
            num=2;
        for (int j=0; j<len; j++)
        {
            total=total*num+a[s[j]];
        }
        return total;
}
int main()
{
  int n;
  scanf("%d\n",&n);
  list *t=(list*)malloc(sizeof(list)*n);
  for(int i=0;i<n;i++)
  {
      scanf("%s\n",t[i].s);
      t[i].n=read(t[i].s);
  }
  qsort(t,n,sizeof(list),cmp);
  for(int i=0;i<n;i++)
    printf("%s\n",t[i].s);
    free(t);
  return 0;
}
