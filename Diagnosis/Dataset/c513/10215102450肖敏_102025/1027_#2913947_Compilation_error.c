#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAD_TO_DEG(180/(4*atan(1)))

typedef struct polar{
double m;
double angle;
}POLAR[100];

int main()
{
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
                POLAR[j].angle = RAD_TO_DEG*atan2(y,x);
            
        }
        int cmp(const void * a,const void * b)
        {
            struct polar *aa=(polar*)a;
            struct polar *bb=(polar*)b;
            if(aa->angle != bb->angle )
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
