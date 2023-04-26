# include<stdio.h>

void printd(long long int n)
{
    printd(n/2333ll);
    printf("%d ",(n%2333ll));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        printd(n);
        printf(" ");
    }
    return 0;
}