#include <stdio.h>
#include <math.h>

int main()
{
    int n,N,x;
    scanf("%d",&N);
    while(n++<N)
    {
        printf("case #%d:\n",n-1);
        scanf("%d",&x);
        double y=pow(2,x);
        printf("%d\n",(int)y);
    }
    return 0;
}
