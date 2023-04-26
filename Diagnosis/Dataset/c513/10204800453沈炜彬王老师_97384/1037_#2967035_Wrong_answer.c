#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

int
main()
{
    int n,m;
    long long int res=0;
    long long int c;
    int pos=1;
    
    scanf("%d%d",&n,&m);
    long long int *pnum = (long long int*)malloc((n+1)*sizeof(long long int));
    
    for (int i=1; i<n+1; i++)
    {
        scanf("%lld",pnum+i);
    }
    qsort(pnum+1, n, sizeof(long long int), cmp);
    
    c = pnum[m]-pnum[1];
    for (int i=1; i+m-1<n+1; i++)
    {
        if (c>(pnum[i+m-1]-pnum[i]))
        {
            pos = i;
            c=(pnum[i+m-1]-pnum[i]);
        }
    }
    for (int i=pos; i<m+pos; i++)
    {
        res += (pnum[m+pos-1]-pnum[i]);
    }
    printf("%lld\n",res);
    free(pnum);
    
    return 0;
}

int
cmp(const void *a,const void *b)
{
    long long int num1 = *((long long int*)a);
    long long int num2 = *((long long int*)b);
    
    if (num1>num2)
        return 1;
    else
        return -1;
}