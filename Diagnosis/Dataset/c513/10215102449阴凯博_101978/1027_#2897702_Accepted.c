#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
    double r;
    double s;
}   POINT;


int cmp(const void* a,const void *b)
{
    POINT* pa=(POINT*)a; POINT* pb=(POINT*)b;
    if (pa->s>pb->s) return 1;
    if (pa->s<pb->s) return -1;
    if (pa->s==pb->s)
    {
        return (pa->r>pb->r)?-1:1;
    }
}


int main()
{
    int T,N;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int j;
        scanf("%d",&N);
        POINT* arr=(POINT*)malloc(N*sizeof(POINT));
        for (j=0;j<N;j++)
        {
            scanf("%lf %lf",&arr[j].x,&arr[j].y);
            arr[j].r=sqrt(pow(arr[j].x,2)+pow(arr[j].y,2));
            arr[j].s=atan2(arr[j].y,arr[j].x);
            if (arr[j].s<0)
                arr[j].s+=2*acos(-1.0);
        }
        qsort(arr,N,sizeof(POINT),cmp);
        for (j=0;j<N;j++)
            printf("(%.4lf,%.4lf)\n",arr[j].r,arr[j].s);
        free(arr);
    }




    return 0;
}
