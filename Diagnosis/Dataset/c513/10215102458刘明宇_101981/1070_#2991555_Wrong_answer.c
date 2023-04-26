#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1){
        double sum = pow(2.0,(double)n);
        double num1 = sum/8.0;
        double sum0 = sum - (double)(n-2) * num1;
        printf("%.0f\n",sum0);
        scanf("%d",&n);
    }
}
