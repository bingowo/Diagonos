#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    double a,b;
    a=*((double *)pa);
    b=*((double *)pb);
    return a>b?1:-1;
}
int main()
{
    int dis;
    scanf("%d",&dis);
    int number;
    scanf("%d",&number);
    int d[number];
    int v[number];
    double v0[number];
    for(int i=0;i<number;i++)
    {
        scanf("%d %d",&d[i],&v[i]);
        v0[i]=dis*v[i]*1.0/(dis-d[i]);
    }
    qsort(v0,number,sizeof(double),cmp);
    printf("%.6f",v0[0]);
    return 0;
}