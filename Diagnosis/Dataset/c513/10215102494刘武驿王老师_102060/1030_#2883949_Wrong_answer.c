#include<stdio.h>
#include<stdlib.h>
struct num
{
    long long int self;
    int max;
};
int cmp(void *a,void*b)
{
    return -((struct num*)a)->max-((struct num*)b)->max;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct num nums[10000];
        int pros;
        scanf("%d",&pros);
        for(int j=0;j<pros;j++)
        {
            scanf("%lld",&nums[j].self);
            long long int tmp=nums[j].self;
            if(nums[j].self<0) tmp=-nums[j].self;
            int maxwid;
            nums[j].max=nums[j].self;
            while(tmp)
            {
                maxwid=tmp%10;
                tmp/=10;
            }
        }
        qsort(nums,pros,sizeof(nums[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<pros-1;j++) printf("%lld ",nums[j].self);
        printf("%lld\n",nums[pros-1].self);
    }
}