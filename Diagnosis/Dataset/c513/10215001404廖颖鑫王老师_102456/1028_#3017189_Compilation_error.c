大润发鲨鱼阿姨:
#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n=1,i,a[100];
    char c;
    scanf("%c",&c);//读取字符到底是A还是D
    getchar();
    while(scanf("%d",&a[n-1])!=EOF)
    {
        n++;
    }
    if(c=='A')
    {qsort(a,n,sizeof(int),cmp1);}//如果是A，就升序，排序规则为cmp1
    if(c=='D')
    {qsort(a,n,sizeof(int),cmp2);}
    //开始删除重复元素
    for (int i = 0; i<n; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                a[i]=a[j];//将后一重复元素放到该元素中
                for(int k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];//将后面的元素一次前移1位
                }
                n--;//元素个数减一
                i--;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d",a[i]);
    return 0;
}

大润发鲨鱼阿姨:
[图片]
