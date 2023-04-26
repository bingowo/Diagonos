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
    if(fabs(s1.q-s2.q)>1e-6)
    {
        if(s1.q>s2.q) return 1;
        else return -1;
    }
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
            double k=atan2(fabs(y),fabs(x));
            if(x>=0 && y>=0) a[j].q=k;
            else if(x<=0 && y>=0) a[j].q=3.14159-k;
            else if(x<=0 && y<=0) a[j].q=3.14159+k;
            else if(x>=0 && y<=0) a[j].q=3.14159*2-k;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int m=0;m<N;m++) printf ("(%.4lf,%.4lf)\n",a[m].p,a[m].q);
    }
    return 0;
}
