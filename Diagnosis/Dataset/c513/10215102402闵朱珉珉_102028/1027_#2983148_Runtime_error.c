#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{double p;double q;} Point;
int cmp(const void *a,const void *b)
{
    Point *a1=(Point*)a,*b1=(Point*)b;
    if (a1->q-b1->q>0) return 1;
    else if (a1->q-b1->q<0) return -1;
    else
    {
        if (b1->p-a1->p>0) return 1;
        else return -1;
    }
}
int main()
{
    int T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N;
        scanf ("%d",&N);
        double x,y;
        Point S[1001];
        for (int j=0;j<N;j++)
        {
            scanf("%lf%lf",x,y);
            S[j].p=hypot(x,y);
            S[j].q=atan2(y,x);
        }
        qsort(S,N,sizeof(S[0]),cmp);
        printf ("case #%d:\n",i);
        for (int j=0;j<N;j++)
        {
            printf("(%.4f,%.4f)\n",S[j].p,S[j].q);
        }
    }
    return 0;
}
