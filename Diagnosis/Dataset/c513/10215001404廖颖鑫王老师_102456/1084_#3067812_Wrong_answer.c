#include <math.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a,b;
     scanf("%d",&a);
     b=pow(2,a);
     printf("case #%d:\n",i);
     printf("%d",b);
    }
}