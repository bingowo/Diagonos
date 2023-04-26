#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926
typedef struct node{
    double x,y;
    double p,o;
}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1,s2;
    s1=*(NODE*)a;
    s2=*(NODE*)b;
    if(s1.o>s2.o)
        return 1;
    else if(s1.o<s2.o)
        return 0;
    else if(s1.p>s2.p)
        return 0;
    else
        return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int k;
        scanf("%d",&k);
        NODE n[k];
        for(int j=0;j<k;j++)
        {
            scanf("%lf %lf",&n[j].x,&n[j].y);
            n[j].p=sqrt(n[j].x*n[j].x+n[j].y*n[j].y);
            n[j].o=atan2(n[j].y,n[j].x);
            if(n[j].o<0)
                n[j].o=2*pi+n[j].o;
            //printf("%.4lf\n",n[j].o);
        }
        qsort(n,k,sizeof(n[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<k;i++)
            printf("%.4lf %.4lf\n",n[i].p,n[i].o);

    }
    return 0;
}
