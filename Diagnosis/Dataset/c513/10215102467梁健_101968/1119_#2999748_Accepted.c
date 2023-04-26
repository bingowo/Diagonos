#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct car
{
    int dis;
    int spe;
}CAR;
int main()
{
    int d;scanf("%d",&d);
    int n;scanf("%d",&n);
    CAR*a=NULL;
    a=(CAR*)malloc(sizeof(CAR)*n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].dis,&a[i].spe);
    }
    double maxs=d/((d-a[0].dis)*1.0/a[0].spe);
    for(int i=1;i<n;i++){
        double time=(d-a[i].dis)*1.0/a[i].spe;
        double s1=d/time;
        if(maxs>s1)maxs=s1;
    }
    printf("%lf",maxs);
    return 0;
}
