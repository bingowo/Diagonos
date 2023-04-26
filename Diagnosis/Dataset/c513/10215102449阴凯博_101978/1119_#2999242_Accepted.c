#include <stdio.h>
#include <stdlib.h>
//
//typedef struct
//{
//    int speed;
//    int distance;
//} CAR;

int cmp(const void* a,const void* b)
{
    double* pa=(double*)a; double* pb=(double*)b;
    return (*pb>*pa)?1:-1;
}

int main()
{
    int d,n;
    scanf("%d",&d);
    scanf("%d",&n);
    double* time=(double*)calloc(n,sizeof(double));
    for (int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        time[i]=(double)(d-x)/y;
    }
    qsort(time,n,sizeof(double),cmp);
    printf("%lf\n",d/time[0]);



    return 0;
}
