#include<stdio.h>

int cmp1(const void*a,const void*b)
{
    int*p1 = (int*)a;
    int*p2 = (int*)b;
    return *p1-*p2;
}

int cmp2(const void*a,const void*b)
{
    int*p1 = (int*)a;
    int*p2 = (int*)b;
    return *p2-*p1;
}

int main()
{
    char style;
    scanf("%c",&style);
    int nums[100];
    int count = 1;
    scanf("%d",&nums[0]);
    while(getchar()!=EOF)
    {
        scanf("%d",&nums[count]);
        count++;
    }
    if(style == 'A')
    {
        qsort(nums,count,sizeof(int),cmp1);
    }
    else{
        qsort(nums,count,sizeof(int),cmp2);
    }
    int flag = nums[0];
    printf("%d ",flag);
    for(int i = 0;i<count-1;i++)
    {
        if(flag == nums[i])
        {
            continue;
        }
        else
        {
            flag = nums[i];
            printf("%d ",flag);
        }
    }
    return 0;
}

