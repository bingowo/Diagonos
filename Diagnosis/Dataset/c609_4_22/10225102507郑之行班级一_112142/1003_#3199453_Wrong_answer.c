#include <stdio.h>
#include <stdlib.h>

void mod2333(long a)
{
    if(a)
    {
        mod2333(a/2333);
        printf("%ld ",a%2333);
    }
}

int main()
{
    int T;scanf("%d",&T);
    long a;
    for (int i=0;i<T;i++)
    {
        scanf("%ld",&a);
        if(a==0){printf("0");return 0;}
        mod2333(a);
        printf("\n");
    }
    return 0;
}
