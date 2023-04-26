#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
    int num[51];
    int len;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    int i,k=0;
    for(i=0;i<c->len&&i<d->len;i++)
    {
        if(c->num[i]!=d->num[i]){return d->num[i]-c->num[i];k=1;break;}
    }
    if(k==0)return d->len-c->len;
}

int main()
{
    int T,t;scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int n;scanf("%n",&n);struct st d[n];
        for(int i=0;i<n;i++)
        {
            int k=0;scanf("%d",&d[i].num[k]);
            while(d[i].num[k]!=-1)
                {scanf("%d",&d[i].num[k+1]);k++;}
            d[i].len=k;
        }
        qsort(d,n,sizeof(d[0]),cmp);    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<d[i].len;j++)
                printf("%d ",d[i].num[j]);
            printf("\n");
        }
    }
}