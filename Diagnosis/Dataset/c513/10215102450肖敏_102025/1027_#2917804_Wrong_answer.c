#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  M_PI 2*3.14159
int main()
{
    struct polar
    {
        double m;
        double angle;
    };

    struct polar POLAR[100];
    int T,i;
    scanf("%d",&T);
    for(i = 0;i <T;i++)
    {
        int N,j;
        scanf("%d",&N);
        for(j = 0;j <N;j++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            POLAR[j].m = sqrt(x*x + y*y);
            if(POLAR[j].m == 0)
                POLAR[j].angle = 0.0;
            else
                POLAR[j].angle = atan2(y,x);

        }
        int cmp(const void * a,const void * b)
        {
            struct polar *aa=(struct polar*)a;
            struct polar *bb=(struct polar*)b;
            if((aa->angle - bb->angle) <1e-7 )
                return aa->angle - bb->angle;
            else
                return bb->m - aa->m;
        }
        qsort(POLAR,N,sizeof(POLAR[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k< N;k ++)
            printf("(%.4f,%.4f)\n",POLAR[k].m,POLAR[k].angle);
    }
    return 0;
}
