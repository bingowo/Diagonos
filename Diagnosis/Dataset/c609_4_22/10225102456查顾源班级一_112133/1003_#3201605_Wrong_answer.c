#include <stdio.h>

void trans(int n)
{if(n>0)
    {trans(n/2333);
    printf("%d",n%2333);
    printf(" ");}}

int main() {
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
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
    return 0;
}