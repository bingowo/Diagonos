#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
  char chr[20];  
};

int cmp(const void*a,const void *b)
{
    int k1=0,k2=0;
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if((*c).chr[0]=='-')k1++;
    if((*d).chr[0]=='-')k2++;
    if((*c).chr[k1]!=(*d).chr[k2])return (*d).chr[k2]-(*c).chr[k1];
    else return (atol((*c).chr)-atol((*d).chr))%10;
}

int main()
{ 
    int T,t;scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int n,j;
        scanf("%d",&n);
        struct st s[n];
        for(j=0;j<n;j++)
            scanf("%s",s[j].chr);
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<n;i++)printf("%s ",s[i].chr);
        printf("\n");
    }
}