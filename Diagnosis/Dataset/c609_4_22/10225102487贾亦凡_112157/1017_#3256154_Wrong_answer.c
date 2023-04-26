#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp1(const void*a,const void *b)
{
    return *(int*)b-*(int*)a;//从大到小排序
}
int cmp2(const void*a,const void *b)
{
    return *(int*)a-*(int*)b;//从小到大排序
}
int main()
{
    char letter;
    int i,j,k,temp;
    scanf("%c",&letter);
    int count=0,num[100];

    //记录长度
    while (scanf("%d",&num[count])!=EOF)
    {
        count++;
    }

    //排序
    if(letter=='A')
    qsort(num,count,sizeof(num[0]),cmp2);
    else
    qsort(num,count,sizeof(num[0]),cmp1);

    //检查重复
    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if(num[i]==num[j])
            {
                for(temp=j;temp<count-1;temp++)
                {
                    num[temp]=num[temp+1];
                    j--;//a[j+1]取代了a[j]的位置为使从a[j+1]开始查找j减一（为使j保持不变）
                    count--;//删去了一个元素
                }
            }
        }
    }
    
    //输出
    printf("%d",num[0]);
    for(k=1;k<count;k++)
        printf(" %d",num[k]);
    return 0;
    
}