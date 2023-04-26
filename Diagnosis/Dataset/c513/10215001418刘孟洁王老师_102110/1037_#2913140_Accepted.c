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
    long long int *sum,*sss;
    scanf("%d%d",&n,&m);
    s = (long long int *)malloc(n * sizeof(long long int));
    sum = (long long int *)malloc((n-m+1)*sizeof(long long int));//记录差之和
    sss = (long long int *)malloc(n*sizeof(long long int));
    for(i = 0;i < n-m+1; i++)sum[i]=0;
    for(i = 0;i < n ; i++)scanf("%lld",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);//从大到小排序
    sss[0] = s[0];
    for(i = 1; i < n; i++)
        sss[i]=sss[i-1]+s[i];//前i个数的和；为使求差之和更简便
    for(i = 0; i <= n-m; i++)
    {
        sum[i] = (m-1) *s[i] -(sss[i+m-1]-sss[i]);//最大数的m-1倍减去后面m-1个数
    }
    printf("%lld",min(sum,i));//取差之和的最小的一个；
    return 0;
}
