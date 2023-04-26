#include <stdio.h>
#include <stdlib.h>
void f(int n,int r);
int main()
{
    int n,r;
    while(scanf("%d %d", &n, &r)!=EOF)
    {
        f(n,r);
        printf("\n");
    }
    return 0;

}
void f(int n,int r)
{
    if(n==0)
        printf("0");
    else
    {
        f(n/r,r);
        printf("%d",n%r);
    }
}