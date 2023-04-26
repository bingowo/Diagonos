#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d=0,n=0;
    scanf("%d %d",&d,&n);
    double maxt=0.0;
    for(int i=0;i<n;i++){
        int wz=0,s=0;
        scanf("%d %d",&wz,&s);
        double t=0.0;
        t=(double)(d-wz)/s;
        if(t>maxt){
            maxt=t;
        }
    }
    double sp=(double)d/maxt;
    printf("%.6f\n",sp);
    return 0;
}
