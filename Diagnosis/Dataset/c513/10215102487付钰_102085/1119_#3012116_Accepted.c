
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int s;
    int v;
    double max;
}car;
int cmp(const void *a,const void *b )
{
    car*p1=(car *)a;
    car*p2=(car*)b;
    if(p1->max>p2->max){//比较t max均可 主要是cmp不能直接减法
        return 1;
    }
    else return -1;
}
int main()
{
    int d;
    scanf("%d",&d);
    int n;
    scanf("%d",&n);
    car a[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].s,&a[i].v);
        int cha=d-a[i].s;
        double t=cha*1.0/a[i].v;
        a[i].max=d/t;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%.6f",a[0].max);
}
