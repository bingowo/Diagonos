#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int r;
    int h;
    long long sc;
}C;

int cmp(const void* a,const void* b)
{
    C aa=*(C*)a,bb=*(C*)b;
    if(aa.sc>bb.sc) return -1;
    else if(aa.sc<bb.sc) return 1;
    return 0;
}

int main()
{
    int n=0,m=0;
    scanf("%d%d",&n,&m);
    C c[1000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&c[i].r,&c[i].h);
        c[i].sc=c[i].r*2*c[i].h;
    }
    qsort(c,n,sizeof(c[0]),cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        long long sd=c[i].r*c[i].r,t=sd+c[i].sc,rt=c[i].r;
        int j=1;
        for(int x=0;j<m&&x<n;x++)
        {
            if(x!=i)
            {
                if(c[x].r<=rt) t+=c[x].sc,rt=c[x].r,j++;
            }

        }
        if(j==m) ans=ans>t?ans:t;
    }
    printf("%lld",ans);
    return 0;
}
