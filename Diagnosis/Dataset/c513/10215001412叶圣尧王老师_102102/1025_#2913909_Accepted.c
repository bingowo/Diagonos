#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
  char chr[21];  
  int num;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->num==d->num)return strcmp(c->chr,d->chr);
    else return d->num-c->num;
}

int main()
{
    int T,i;scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n,j,k;scanf("%d",&n);struct st s[n];
        for(j=0;j<n;j++)
        {
            scanf("%s",s[j].chr);s[j].num=0;int b[26]={0};
            for(k=0;k<strlen(s[j].chr);k++)
            {
                if(b[s[j].chr[k]-'A']==0)s[j].num++;
                b[s[j].chr[k]-'A']++;
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)printf("%s\n",s[j].chr);
    }
}