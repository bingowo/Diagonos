#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void *a,const void *b)
{
    double *s1=(double*)a,*s2=(double *)b;
    if(s1[1]>s2[1]) return 1;
    else if(s1[1]<s2[1]) return 0;
    else if(s1[1]==s2[1])
    {
        if(s1[0]>=s2[0]) return 0;
        else return 1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        double s[n][2];
        for(int j=0;j<n;j++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            s[j][1]=atan2(y,x);
            if(s[j][1]<0) s[j][1]+=2*acos(-1);
            s[j][0]=sqrt(x*x+y*y);
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("(%.4lf,%.4lf)\n",s[j][0],s[j][1]);
        }
    }
    return 0;
}
