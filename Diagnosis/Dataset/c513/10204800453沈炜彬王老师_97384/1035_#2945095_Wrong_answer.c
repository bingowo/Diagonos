#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

typedef struct
{
    int R;
    int H;
}col;

int
main()
{
    int n,m;
    int max,temp;
    int pos=0;
    int res=0;
    
    scanf("%d%d",&n,&m);
    col *pcol = (col*)malloc(n*sizeof(col));
    col *pcol2 = (col*)malloc(n*sizeof(col));
    for (int i=0; i<n; i++)
    {
        scanf("%d%d",&((pcol+i)->R),&((pcol+i)->H));
    }
    qsort(pcol, n, sizeof(col), cmp);
    max = 0;
    for (int i=0; i<n; i++)
    {
        temp = (pcol+i)->R;
        if (max < temp)
        {
            max = temp;
            pos = i;
        }
    }
    pcol2->R = (pcol+pos)->R;
    pcol2->H = (pcol+pos)->H;
    for (int i=1; i<n; i++)
    {
        if (i == pos)
        {
            continue;
        }
        else if (i<pos)
        {
            (pcol2+i)->R = (pcol+i-1)->R;
            (pcol2+i)->H = (pcol+i-1)->H;
        }
        else
        {
            (pcol2+i)->R = (pcol+i)->R;
            (pcol2+i)->H = (pcol+i)->H;
        }
    }
    for (int i=0; i<m; i++)
    {
        res += 2*((pcol2+i)->R)*((pcol2+i)->H);
    }
    res += (pcol2->R)*(pcol2->R);
    printf("%d\n",res);
    
    return 0;
}

int
cmp(const void *a,const void *b)
{
    int num1 = ((col*)a)->R;
    int num2 = ((col*)b)->R;
    int num3 = ((col*)a)->H;
    int num4 = ((col*)b)->H;
    long long int res1 = num1*num3;
    long long int res2 = num2*num4;
    
    if (res1 < res2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}