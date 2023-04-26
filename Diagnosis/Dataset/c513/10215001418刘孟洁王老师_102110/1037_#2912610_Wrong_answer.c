#include <stdio.h>
#include <stdlib.h>

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
    long long int sum;
    long long int *t,*s;
    scanf("%d%d",&n,&m);
    s = (int *)malloc(n * sizeof(int));
    t = (int *)malloc(m * sizeof(int));
    for(i = 0;i < n ; i++)scanf("%lld",&s[i]);
    
    qsort(s,n,sizeof(s[0]),cmp);
    for(j = n-1,k = 0; k < m ;k++,j--)t[k] = s[j];
    
    for(k = 0,sum = 0;k < m; k++)sum = sum+t[m-1]-t[k];
    printf("%lld",sum);
    return 0;
}
