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
        long long int sum[5000];
        long long int nums[1000],count=0;
        memset(sum,0,5000);
        memset(nums,0,1000);
        for(int j=1;j<=n;j++) {scanf("%d",nums+j);nums[j]+=nums[j-1];}
        for(int len=1;len<=n;len++)
            for(int i=1;i<=n-len+1;i++)
                sum[++count]=nums[i+len-1]-nums[i-1];
        qsort(sum,count,sizeof(sum[0]),cmp);
        long long int sum1[5000];
        memset(sum1,0,5000);
        for(int i=1;i<count;i++) for(int j=1;j<=i;j++) sum1[i]+=sum[j];
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int p,q;
            scanf("%d %d",&p,&q);
            printf("%lld\n",sum1[q]-sum1[p-1]);
        }
    }
}
