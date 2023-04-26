#include<stdio.h>
#include <stdlib.h>


long long int min(long long int s[],int n)
{
    int i = 0;
    while(i<n-1)
    {
       if(s[i] < s[i+1]) s[i+1] = s[i] , i++;
        else i++;
    }
    return s[i];
}

int cmp(const void*a,const void*b)
{
    long long int c = *(long long int *)a;
    long long int d = *(long long int *)b;
    if(c < d)return 1;
    else return -1;
}

int main()
{
    int n,m,i,j,k;
    long long int *s;
    long long int *sum;
    scanf("%d%d",&n,&m);
    s = (long long int *)malloc(n * sizeof(long long int));
    sum = (long long int *)malloc((n-m+1)*sizeof(long long int));
    for(i = 0;i < n-m+1; i++)sum[i]=0;
    for(i = 0;i < n ; i++)scanf("%lld",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(i = 0; i <= n-m; i++)
    {
        for(j = i+1, k = 0; k < m-1; k++, j++)
        {
            sum[i] = sum[i] + s[i]-s[j];
        }
    }
    printf("%lld",min(sum,i));
    return 0;
}
