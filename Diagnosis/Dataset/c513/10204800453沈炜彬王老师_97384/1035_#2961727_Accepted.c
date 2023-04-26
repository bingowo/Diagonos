#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

typedef struct
{
    long long int R;
    long long int H;
    long long int S;
}col;

int
main()
{
    int n,m;
    long long int res=0;
    long long int temp=0;
    int count=1;
    
    scanf("%d%d",&n,&m);
    col *pcol = (col*)malloc(n*sizeof(col));
    for (int i=0; i<n; i++)
    {
        scanf("%lld%lld",&((pcol+i)->R),&((pcol+i)->H));
        pcol[i].S = 2 * pcol[i].R * pcol[i].H;
    }
    qsort(pcol, n, sizeof(col), cmp);

    for (int i=0; i<n; i++)
    {
        temp = pcol[i].S + pcol[i].R * pcol[i].R;
        count = 1;
        for (int j=0; j<n && count<m; j++)
        {
            if (i==j || pcol[i].R<pcol[j].R) continue;
            count++;
            temp += pcol[j].S;
        }
        res = res>temp?res:temp;
    }
    printf("%lld\n",res);
    
    return 0;
}

int
cmp(const void *a,const void *b)
{
    long long int s1 = ((col*)a)->S;
    long long int s2 = ((col*)b)->S;
    
    if (s1<s2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}