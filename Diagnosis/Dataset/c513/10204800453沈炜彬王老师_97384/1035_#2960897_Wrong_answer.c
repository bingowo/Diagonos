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
    long long int res=0;
    long long int temp=0;
    int count=1;
    
    scanf("%d%d",&n,&m);
    col *pcol = (col*)malloc(n*sizeof(col));
    for (int i=0; i<n; i++)
    {
        scanf("%d%d",&((pcol+i)->R),&((pcol+i)->H));
    }
    qsort(pcol, n, sizeof(col), cmp);
    
    for (int i=0; i<n; i++)
    {
        temp = (*(pcol+i)).H * (*(pcol+i)).R * 2 + (*(pcol+i)).R * (*(pcol+i)).R;
        count=1;
        for (int j=0; j<n && count<m; j++)
        {
            if (i==j || (*(pcol+i)).R < (*(pcol+j)).R ) continue;
            count++;
            temp += (*(pcol+j)).H * (*(pcol+j)).R * 2;
        }
        if (m==count)
        {
            res = temp>res?temp:res;
        }

       
    }
    printf("%lld\n",res);
    
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