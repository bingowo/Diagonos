#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define LEN 110

typedef long long int lli;

long long int max(long long int a,long long int b)
{
    return a>b ? a:b;
}

long long  abs(long long int x)
{
    return x>0 ? x : -1 * x;
}

int main()
{
    long long int x0,y0,min_x,min_y,min;
    min_x=min_y=min=LLONG_MAX;
    scanf("%lld %lld",&x0,&y0);
    int n;
    scanf("%d",&n);
    long long int x[n],y[n],dis;
    for (int i=0; i<n; i++) {
        scanf("%lld %lld",&x[i],&y[i]);
        dis=max(abs(x[i]-x0), abs(y[i]-y0));
        if (dis<min) {
            min=dis;
            min_x=x[i];
            min_y=y[i];
        }
        else if(dis==min){
            if (x[i]<min_x) {
                min_x=x[i];
                min_y=y[i];
            }
            else if(x[i]==min_x&&y[i]<min_y){
                min_x=x[i];
                min_y=y[i];
            }
        }
    }
    printf("%lld\n%lld %lld",min,min_x,min_y);
    return 0;
}
