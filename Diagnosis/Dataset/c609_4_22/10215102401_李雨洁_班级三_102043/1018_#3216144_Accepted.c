#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void F(int a[],int n)//升序
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[100001]={0};//初始化
    for(int z=0;z<n;z++)
    {
        scanf("%d",&a[z]);
    }
    //F(a,n);冒泡排序太耗时间
    qsort(a,n,sizeof(a[0]),cmp);
    int end=0;
    for(int i=0;i<n;i+=2)
    {
        end+= (a[i+1]-a[i]);
    }
    printf("%d",end);
    return 0;
}
