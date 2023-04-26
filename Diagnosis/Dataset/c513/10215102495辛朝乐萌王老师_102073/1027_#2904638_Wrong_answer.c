#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct{
    double rou;
    double theta;
}polo;

int cmp(const void *a,const void *b)
{
    polo *p1,*p2;
    p1=(polo *)a;
    p2=(polo *)b;
    return p1->theta>p2->theta?1:-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int t;
        scanf("%d",&t);
        for (int i=0; i<t; i++) {
            double x;
            double y;
            scanf("%lf %lf",&x,&y);
        }
    }
}
