#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data
{
    double d;
    double r;
};
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.r>b.r)
    {
        return 1;
    }
    else if(a.r<b.r)
    {
        return -1;
    }
    else
    {
        if(a.d>b.r)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a;
        scanf("%d",&a);
        double x[a];
        double y[a];
        struct data p[a];
        for(int j=0;j<a;j++)
        {
            scanf("%f",&x[j]);
            scanf("%f",&y[j]);
            p[j].d=sqrt(x[j]*x[j]+y[j]*y[j]);
            if(y>=0)
            {
                p[j].r=atan(x[j]*x[j]+y[j]*y[j]);
            }
            else
            {
                p[j].r=atan(x[j]*x[j]+y[j]*y[j])+1;
            }
        }
        qsort(p,a,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<a;k++)
        {
            printf("(");
            printf("%4f",p[a].d);
            printf(",");
            printf("%4f",p[a].r);
            printf(")\n");
        }
    }
    return 0;
}