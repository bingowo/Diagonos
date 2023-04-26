#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st
{
    char c[16];
    int num[16];
    int k;
    long long sum;
};

int cmp(const void*a,const void*b)
{
    struct st*e=(struct st*)a;
    struct st*d=(struct st*)b;
    if(e->sum!=d->sum)return e->sum>d->sum;
    else return strcmp(e->c,d->c);
}

int main()
{
    int T,i,j,k;char s[16];
    scanf("%d",&T);struct st d[T];
    for(int t=0;t<T;t++)
    {
        scanf("%s",s);k=0;
        d[t].c[0]=s[0];d[t].num[0]=1;d[t].k=1;
        for(i=1;i<strlen(s);i++)
        {
            d[t].c[i]=s[i];
            for(j=0;j<i;j++)
            if(d[t].c[j]==s[i])
            {
                d[t].num[i]=d[t].num[j];
                break;
            }
            if(j==i)
            {
                if(k==1)k++;
                d[t].num[i]=k++;
                d[t].k++;
            }
        }
        d[t].c[i]='\0';d[t].sum=0;
        if(d[t].k==1)d[t].k++;
        for(i=0;i<strlen(s);i++)
        d[t].sum=d[t].sum*d[t].k+d[t].num[i];
    }
    qsort(d,T,sizeof(d[0]),cmp);
    for(i=0;i<T;i++)
        printf("%s\n",d[i].c);
}