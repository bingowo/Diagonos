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
    printf("%d",num[0]);
    for(i=0;i<count-1;i++)
    {
        j=i+1;
        if(num[i]!=num[j])
        printf(" %d",num[j]);
    }
    return 0;
    
}