#include <stdio.h>
#include <stdlib.h>

int GETN(int n)
{
    if (n<5)
    {
        return 0;
    }
    else
    {
        return (n/5+GETN(n/5));
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        printf("%d\n",GETN(N));

    }
    return 0;
}
