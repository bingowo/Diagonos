#include <stdio.h>
void table(int n)
{
    while(n!=0)
    {
    table(n/2333);
    printf("%d ",n%2333);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
    int m=2333;
    float n;
    scanf("%f\n",&n);
    if (n<0)
    {
        putchar('-');
        n=-n;
    }
    if(n==0)
        putchar('0');
    else

        table(n);

    putchar('\n');
    }

    return 0;
}