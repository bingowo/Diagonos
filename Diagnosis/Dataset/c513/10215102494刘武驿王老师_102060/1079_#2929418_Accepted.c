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
        for(int j=1;j<=n;j++) {scanf("%d",nums+j);nums[j]+=nums[j-1];}
        for(int len=1;len<=n;len++)
            for(int i=1;i<=n-len+1;i++)
                sum[++count]=nums[i+len-1]-nums[i-1];
        qsort(sum,count+1,sizeof(sum[0]),cmp);
        long long int sum1[500030];
        memset(sum1,0,500030);
        for(int i=1;i<=count;i++) sum[i]+=sum[i-1];
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            printf("%lld\n",sum[q]-sum[p-1]);
        }
    }
}
