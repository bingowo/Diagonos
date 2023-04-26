#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double number(double n,double m)
{
    if(n == m)return 1;
    else if(m == n-1)return 3;
    if(m == 1)return pow(2,n)-1;
    if(m == 2)return pow(2,n)-1-n;
    if(n == 5 && m == 3)return 9;
    if(n > 5) return number(n,m+1) + pow(2,n-m-2) + pow(2,n-m-1)*2;
}

int main()
{
    double m,n;
    while(1)
    {
        scanf("%lf%lf",&n,&m);
        if(n == -1 && m == -1)break;
        else printf("%.0lf\n",number(n,m));
        //printf("%.0lf\n%.0lf\n",m,pow(2,n)-1);
    }
    return 0;
}