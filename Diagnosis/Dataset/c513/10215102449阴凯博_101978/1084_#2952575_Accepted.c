#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        unsigned long long m;
        m=1<<N;
        printf("%llu\n",m);
    }
    return 0;
}
