#include <stdio.h>

void trans(long long n)
{if(n>0)
    {trans(n/2333);
        printf("%lld",n%2333);
        printf(" ");}}

int main() {
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<=T/2;i++)
    {scanf("%d",&n);
        if(n<0)
        {printf("-");
            n=-n;}
        if(n==0)
            printf("0");
        else
            trans(n);
        printf("\n");
    }
    for(int i=T/2;i<T;i++)
    {scanf("%lld",&n);
        if(n<0)
        {printf("-");
            n=-n;}
        if(n==0)
            printf("0");
        else
            trans(n);
        printf("\n");
    }
    return 0;
}