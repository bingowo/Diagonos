#include <stdio.h>
#include <stdlib.h>
int binary(long long int x)
{
    int remainder,move = 0,e = 0;
    if(x >= 0)
    {
        do
        {
            remainder = x%2;
            x /= 2;
            if(remainder == 1)
                e++;
        }while(x != 0);
    }
    else
    {
        while(move < 64)
        {
            if((1<<move)&x)
            {
                e++;
                move++;
            }
        }
    }
    return e;

}
int cmp(const void*a, const void*b)
{
    long long int c,d;
    c = *(long long int*)a;
    d = *(long long int*)b;
    if(binary(c) == binary(d))
        return c - d;
    else
        return binary(d) - binary(c);

}
int main()
{
    int T, i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N, j;
        scanf("%d",&N);
        long long int input[N];
        qsort(input, N, sizeof(input[0]), cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
            printf("%lld%c",input[j],(j==N - 1)?'\n':' ');
        putchar('\n');
    }
    return 0;
}
