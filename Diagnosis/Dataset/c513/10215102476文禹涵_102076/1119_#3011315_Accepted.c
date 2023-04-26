#include <stdio.h>
int main()
{
    int d, n;
    scanf("%d %d", &d, &n);
    double maxsec = 0;
    double dis, v;
    for(int i = 0 ; i < n ; i ++){
        scanf("%lf %lf", &dis, &v);
        if((d - dis) / v > maxsec){
            maxsec = (d - dis) / v;}
        }
    printf("%.6lf", d / maxsec);
    return 0;
}