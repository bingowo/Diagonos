#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int N;scanf("%d",&N);
    while(N!=0){
        double a=N*log10(N);
        double ans=0;
        double b=modf(a,&ans);
        int c=(int)pow(10,b);
        printf("%d\n",c);

        scanf("%d",&N);
    }
}
