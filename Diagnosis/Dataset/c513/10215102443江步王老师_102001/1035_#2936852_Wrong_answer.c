#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct s
{
    int radius;
    int height;
}cylinder;

int cmp(const void *_a, const void *_b);

int main()
{
    int n,m;
    int i;
    int s;
    scanf("%d %d",&n,&m);
    cylinder *a = (cylinder *)malloc(sizeof(cylinder)*n);

    //读入每个圆柱的数据
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].radius,&a[i].height);
    }

    qsort(a,n,sizeof(cylinder),cmp);

    //计算最大可视表面积
    s=pow(a[0].radius,2);
    for (i=0;i<m;i++)
    {
        s+=2*a[i].radius*a[i].height;
    }

    //输出
    printf("%d",s);
    return 0;
}


int cmp(const void *_a, const void *_b)
{
    cylinder *a = (cylinder *)_a;
    cylinder *b = (cylinder *)_b;
    if ((*b).radius > (*a).radius)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}