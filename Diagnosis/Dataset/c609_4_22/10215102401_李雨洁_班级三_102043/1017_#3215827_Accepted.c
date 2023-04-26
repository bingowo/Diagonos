#include <stdio.h>
#include <stdlib.h>
int main()
{
    char m;
    scanf("%c", &m);
    int nums[1001]={0},i;//用数组下标存储数值来进行排序
    while((scanf("%d" , &i)) != EOF) nums[i]++;
    if(m == 'A')
    {
        for(i=0; i<=1000 ; i++)
        {
            if(nums[i]>0)  printf("%d ",i);
        }
    }
    else
    {
        for(i = 1000; i > 0 ; --i)
        {
            if(nums[i]>0) printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}
