#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct SSS
{
    double p;
    double q;
};
int cmp(const void *a, const void *b)
{
    struct SSS s1,s2;
    s1=*((struct SSS*)a);
    s2=*((struct SSS*)b);
    if(s1.q!=s2.q) return s1.q-s2.q;
    else
    {
        if(s1.p>s2.p) return -1;
        else return 1;
    }
}
int main()
{
    int T;
    struct SSS a[1000];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            a[j].p=sqrt(x*x+y*y);
            a[j].q=atan2(y,x);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<N;m++) printf ("(%lf,%lf)\n",a[m].p,a[m].q);
    }
    return 0;
}
