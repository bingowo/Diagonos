#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.1415926
int cmp(const void *p1,const void *p2){
    double *a=(double *)p1;
    double *b=(double *)p2;
    if(a[1]==b[1])return b[0]>a[0];
    return a[1]>b[1];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        double x,y;
        scanf("%d",&N);
        double a[1000][2]={0};
        for(int j=0;j<N;j++)
        {
            scanf("%f%f",&x,&y);
            a[j][0]=sqrt(x*x+y*y);
            a[j][1]=atan2(y,x);
            if(a[j][1]<0)a[j][1]+=pi*2;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {
            printf("(%.4f,%.4f)\n",a[k][0],a[k][1]);
        }
    }
    return 0;
}