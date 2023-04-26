#include<stdio.h>
#include<stdlib.h>
int cmp(void *a,void *b)
{
    long long int *a1=(long long int *)a;
    long long int *b1=(long long int *)b;
    long long int numa=*a1,numb=*b1;
    int resa,resb;
    resa=numa;
    resb=numb;
    while(numa)
    {
        resa=numa%10;
        numa/=10;
    }
    while(numb)
    {
        resb=numb%10;
        numb/=10;
    }
    return numa-numb;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int nums[10000];
        int pros;
        scanf("%d",&pros);
        for(int j=0;j<pros;j++) 
        {
            scanf("%lld",&nums[j]);
            if(nums[j]<0) nums[j]=-nums[j];
        }
        qsort(nums,pros,sizeof(nums[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<pros-1;j++) printf("%lld ",nums[j]);
        printf("%lld\n",nums[pros-1]);
    }
}