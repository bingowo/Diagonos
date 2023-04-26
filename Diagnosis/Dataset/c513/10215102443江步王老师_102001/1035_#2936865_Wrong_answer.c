#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct s
{
    long long radius;
    long long height;
}cylinder;

int cmp(const void *_a, const void *_b);

int main()
{
    long long n,m;
    int i;
    long long s;
    scanf("%lld %lld",&n,&m);
    cylinder *a = (cylinder *)malloc(sizeof(cylinder)*n);

    //读入每个圆柱的数据
    for (i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].radius,&a[i].height);
    }

    qsort(a,n,sizeof(cylinder),cmp);

    //计算最大可视表面积
    s=pow(a[0].radius,2);
    for (i=0;i<m;i++)
    {
        s+=2*a[i].radius*a[i].height;
    }

    //输出
    printf("%lld",s);
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