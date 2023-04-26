#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

int
main()
{
    int n,m;
    long long int res=0;
    long long int temp1=0;
    long long int temp2=0;
    
    scanf("%d%d",&n,&m);
    long long int *pnum = (long long int*)malloc((n+1)*sizeof(long long int));
    
    for (int i=1; i<n+1; i++)
    {
        scanf("%lld",pnum+i);
    }
    qsort(pnum+1, n, sizeof(long long int), cmp);
    for (int i=1; i<m; i++)
    {
        res += (pnum[m]-pnum[i]);
    }
    temp1 = res;
    for (int i=2; i+m<n+1; i++)
    {
        temp2 = temp1;
        temp2 += (m*(pnum[i+m]-pnum[i+m-1]));
        temp2 -= (pnum[i+m]-pnum[i]);
        temp1 = temp2;
        res = res<temp2?res:temp2;
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