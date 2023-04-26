#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        double a;
        int N;
        scanf("%d",&N);
        a=pow(2,N);
        printf("case #%d:\n",i);
        printf("%f\n",a);
    }
    return 0;
}
