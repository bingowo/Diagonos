#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
double x;
double y;
double l;
double rad;
}res;
int cmp(const void*a,const void*b)
{
    res m,n;
    m = *(res*)a;n = *(res*)b;
    if(m.rad>n.rad) return 1;
    else if(m.rad == n.rad&&m.l<n.l) return 1;
    else return -1;

}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        res a[N];
        for(j = 0;j<N;j++)
            {
                scanf("%lf %lf",&a[j].x,&a[j].y);
                a[j].l = sqrt(a[j].x*a[j].x+a[j].y*a[j].y);
                a[j].rad = atan2(a[j].y,a[j].x);
                if(a[j].rad<0) a[j].rad = 2*3.1415926+a[j].rad;
            }
        qsort(a,N,sizeof(res),cmp);
        printf("case #%d:\n",i);
        for(j = 0;j<N;j++)
            printf("(%.4f,%.4f)\n",a[j].l,a[j].rad);
    }
    return 0;
}
