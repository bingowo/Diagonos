#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI acos(-1)

int main()
{
    int T;
    scanf("%d",&T);

    double x[1000],y[1000],z[1000],p[1000];//分别对应横纵坐标、极角值、极径

    for( int i = 0 ; i < T ; i++)
    {
        int N;
        scanf("%d",&N);
        for( int j = 0 ; j < N ; j++)
        {
            scanf("%lf %lf",x[j],y[j]);
            z[j] = atan( y[j] / x[j] );
            p[j] = sqrt( x[j] * x[j] + y[j] * y[j] );
        }

        for(int i = 0; i < N - 1; i++)
        {
            for(int j = 0; j < N - i - 1; j++)
            {
                if( z[j] > z[j+1] )
                {
                    double temp;
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = p[j];
                }
            }
        }

        printf("case #%d:\n",i);
        for( int k = 0 ; k < N ; k++)
            printf("(%.4lf,%.4lf)\n",p[k],z[k] * PI);
    }
    return 0;
}
