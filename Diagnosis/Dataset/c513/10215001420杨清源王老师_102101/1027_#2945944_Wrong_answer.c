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
            scanf("%lf%lf",&x[j],&y[j]);


            if( x[j] == 0 && y[j] > 0 )
                z[j] = PI / 2;
            if( x[j] == 0 && y[j] == 0 )
                z[j] = 0;
            else if( x[j] == 0 && y[j] < 0 )
                z[j] = 3 * PI / 2;
            else if( x[j] > 0 && y[j] >= 0 )
                z[j] = atan( y[j] / x[j] );
            else if( x[j] > 0 && y[j] <= 0 )
                z[j] = 2 * PI + atan( y[j] / x[j] );
            else if( x[j] < 0 && y[j] <= 0 )
                z[j] = PI + atan( y[j] / x[j] );
            else if( x[j] < 0 && y[j] >= 0 )
                z[j] = PI + atan( y[j] / x[j] );

            p[j] = sqrt( x[j] * x[j] + y[j] * y[j] );

        }

        for(int m = 0; m < N - 1; m++)
        {
            for(int n = 0; n < N - m - 1; n++)
            {
                if( z[n] > z[n+1] )
                {
                    double temp;
                    temp = p[n];
                    p[n] = p[n+1];
                    p[n+1] = temp;

                    temp = z[n];
                    z[n] = z[n+1];
                    z[n+1] = temp;
                }
            }
        }

        for(int m = 0; m < N - 1; m++)
        {
            for(int n = 0; n < N - m - 1; n++)
            {
                if( z[n] == z[n+1] )
                {
                    if( p[n] > p[n+1] )
                    {
                        double temp;
                        temp = p[n];
                        p[n] = p[n+1];
                        p[n+1] = temp;
                    }
                }
            }
        }

        printf("case #%d:\n",i);
        for( int k = 0 ; k < N ; k++)
            printf("(%.4lf,%.4lf)\n",p[k],z[k]);
    }
    return 0;
}
