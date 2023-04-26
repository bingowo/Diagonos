#include <math.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        double a;int b;
     scanf("%lf",&a);
     b=pow(2,a);
     printf("case #%d:\n",i);
     printf("%d\n",b);
    }
}