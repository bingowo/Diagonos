#include <stdio.h>
#include <stdlib.h>

void slv()
{
    int n,m=5;
    scanf("%d",&n);
    int rt=0;
    while(n>=m)
    {
        rt+=n/m;
        m*=5;
    }
    printf("%d\n",rt);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        slv();
    }
    return 0;
}
