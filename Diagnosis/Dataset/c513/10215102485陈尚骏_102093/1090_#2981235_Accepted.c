#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int N;
    scanf("%d",&N);
    while(N)
    {
        double a,x;
        a=N*log10(N);
        a-=(int)a;
        x=pow(10,a);
        printf("%d\n",(int)x);
        scanf("%d",&N);
    }
    return 0;
}
