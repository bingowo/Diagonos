#include<stdio.h>
#include<math.h>
int main()
{
    int d;
    scanf("%d",&d);
    int n;
    scanf("%d",&n);
    double k[1000];
    double s[1000];
    double time=0.0;

    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&k[i],&s[i]);
        double temp=(d-k[i])/s[i];
        if(temp>time)
        {
            time=temp;
        }
    }
    double v=d/time;
    printf("%.6f\n",v);
}
