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
    long long n,m,num;
    int i,j;
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
    long long max=0;
    for (i=0;i<n;i++)
    {
        s=pow(a[i].radius,2)+2*a[i].radius*a[i].height;
        num=1;
        for (j=0;j<n;j++)
        {
            if (i == j || a[j].radius > a[i].radius)
            {
                continue;
            }
            else
            {
                s+=2*a[j].radius*a[j].height;
                num++;
            }
            if (num == m)
            {
                if (max < s)
                {
                    max=s;
                }
                break;
            }
        }
    }

    //输出
    printf("%lld",max);
    return 0;
}


int cmp(const void *_a, const void *_b)
{
    cylinder *a = (cylinder *)_a;
    cylinder *b = (cylinder *)_b;
    if ((*b).radius*(*b).height > (*a).radius*(*a).height)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}