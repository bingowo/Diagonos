#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int quesnum;
    scanf("%d",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int kazu;
        scanf("%d",&kazu);
        for(int j=0;j<kazu;j++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            printf("(%.4lf %.4lf)\n",sqrt(x*x+y*y),atan2(y,x));
        }
    }
    return 0;
}
