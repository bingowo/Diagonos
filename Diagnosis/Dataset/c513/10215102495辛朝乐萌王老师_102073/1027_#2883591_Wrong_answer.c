#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solve()
{
    int t;
    double l,result;
    double x[100];
    double y[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%lf %lf",&x[i],&y[i]);
        l = fabs(x[i]*x[i]+y[i]*y[i]);
        result = tan(y[i]/x[i]);
        printf("(%.4f,%.4f)\n",l,result);
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        solve();
        printf("\n");
    }
    return 0;
}