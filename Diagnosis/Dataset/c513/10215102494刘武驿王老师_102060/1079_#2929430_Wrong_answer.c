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
        long long int sum[500030];
        long long int nums[1000],count=0;
        memset(sum,0,500030);
        memset(nums,0,1000);
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
        long long int sum1[500030];
        memset(sum1,0,500030);
        for(int i=0;i<count;i++) sum[i]+=sum[i-1];
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            printf("%lld\n",sum[q-1]-sum[p-2]);
        }
    }
}
