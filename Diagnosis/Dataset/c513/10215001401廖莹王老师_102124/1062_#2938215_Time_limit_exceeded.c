#include <stdio.h>
#include <stdlib.h>
long long zoufa(int n)
{
    switch(n)
    {
        case 1:return 1;
        case 2:return 2;
        case 3:return 4;
        case 4:return 8;
        default:return zoufa(n-1)+zoufa(n-2)+zoufa(n-3)+zoufa(n-4);
    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
    {
        int n;
    scanf("%d",&n);
    printf("case #%d:\n",h);
    printf("%lld\n",zoufa(n));
    }

    return 0;
}
