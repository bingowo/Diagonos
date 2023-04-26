#include<stdio.h>
#include<string.h>
int cmp(void *a,void *b)
{
    if(*(long long int *)a>*(long long int *)b) return 1;
    if(*(long long int *)a<*(long long int *)b) return -1;
    else return 0;
}
int main()
{
    int pro;
    scanf("%d",&pro);
    for(int i=0;i<pro;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        long long int sum[5000300];
        long long int nums[2000],count=0;
        memset(sum,0,5000300);
        for(int j=0;j<n;j++) scanf("%d",&nums[j]);
        for(int j=0;j<n;j++)
        {
            for(int w=0;w<=j;w++)
            {
                for(int x=w;x<=j;x++)
                {
                    sum[count]+=nums[x];
                }
                count++;
            }
        }
        qsort(sum,count,sizeof(sum[0]),cmp);
        long long int sum1[5000300];
        memset(sum1,0,5000300);
        for(int i=0;i<count;i++) for(int j=0;j<=i;j++) sum1[i+1]+=sum[j];
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            printf("%lld\n",sum1[q]-sum1[p-1]);
        }
    }
}
