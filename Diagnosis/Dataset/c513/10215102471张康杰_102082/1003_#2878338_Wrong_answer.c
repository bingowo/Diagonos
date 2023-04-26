#include <stdio.h>
#include <stdlib.h>
int binary(int x)
{
    int i,count = 0;
    for(i = 0;i < 32;i++)
    {
        if((x&(1<<i)) != 0)
            count++;
    }

    return count;

}
int cmp(const void*a, const void*b)
{
    int c,d;
    c = *(int*)a;
    d = *(int*)b;
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
        int input[N];
        for(j = 0;j < N;j++)
            scanf("%d",&input[j]);
        qsort(input, N, sizeof(input[0]), cmp);
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
            printf("%d%c",input[j],(j==N - 1)?'\n':' ');
        putchar('\n');
    }
    return 0;
}
