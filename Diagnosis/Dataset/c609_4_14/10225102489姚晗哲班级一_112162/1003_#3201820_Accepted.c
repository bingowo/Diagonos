#include <stdio.h>
void table(long long int n)
{
    if(n>0)
    {
    table(n/2333);
    printf("%lld ",n%2333);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
    int m=2333;
    long long int n;
    scanf("%lld\n",&n);
    if (n<0)
    {
        putchar('-');
        n=-n;
    }
    if(n==0)
        putchar('0');
    else
        table(n);

    printf("\n");
    }

    return 0;
}
