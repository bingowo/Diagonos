#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void * b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n, s, height, i, lower, upper;
    scanf("%d%d",&n,&s);
    int a[n];
    for( i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    //输入完成

    //对a从低到高排序
    qsort(a,n,sizeof(a[0]),cmp);

    height = a[0];//初始化当前高度值

    printf("%d",height);

}
