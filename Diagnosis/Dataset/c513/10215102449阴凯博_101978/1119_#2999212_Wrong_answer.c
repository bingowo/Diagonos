#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int speed;
    int distance;
} CAR;

int cmp(const void* a,const void* b)
{
    CAR* pa=(CAR*)a; CAR* pb=(CAR*)b;
    return (pb->distance-pa->distance);
}

int main()
{
    int d,n;
    scanf("%d",&d);
    scanf("%d",&n);
    CAR* arr=(CAR*)malloc(n*sizeof(CAR));
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d %d",&x,&arr[i].speed);
        arr[i].distance=d-x;
    }
    int vv;
    double t;
    if (n==1)
        t=(double)arr[0].distance/arr[0].speed;
    else
    {
        qsort(arr,n,sizeof(CAR),cmp);
        for (int i=0;i<n-1;i++)
        {
            if (arr[i].speed<=arr[i+1].speed)
                vv=i;
            else
                vv=i+1;
        }
        t=(double)arr[vv].distance/arr[vv].speed;
    }
    printf("%lf\n",d/t);



    return 0;
}
