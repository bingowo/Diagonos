#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct S
{
    double p;
    double q;
};

int cmp(const void *a, const void *b)
{
    struct S s1,s2;
    s1 = *((struct S*)a);
    s2 = *((struct S*)b);
    if(s1.q > s2.q) return 1;
    else if(s1.q < s2.q) return -1;
    else
    {
        if(s1.p > s2.p) return -1;
        else return 1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    struct S a[1000];
    for(int i = 0; i < T; i++)
    {
        int N;
        scanf("%d",&N);
        for(int j = 0; j < N; j++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            a[j].p = sqrt( x * x + y * y);//求平方根
            double k = atan2(fabs(y),fabs(x));//计算方位角
            if(x >= 0 && y >= 0)
                a[j].q = k;
            else if(x <= 0 && y >= 0)
                a[j].q = 3.14159 - k;
            else if(x <= 0 && y <= 0)
                a[j].q = 3.14159 + k;
            else if(x >= 0 && y <= 0)
                a[j].q = 3.14159 * 2 - k;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int m = 0; m < N; m++)
        {
             printf ("(%.4lf,%.4lf)\n",a[m].p,a[m].q);
        }
    }
    return 0;
}
