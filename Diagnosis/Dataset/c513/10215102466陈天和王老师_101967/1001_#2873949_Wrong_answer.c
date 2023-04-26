#include <stdio.h>
#include <stdlib.h>
void f(int n,int r);
int main()
{
    int num;
    scanf("%d",&num);
    int n,r;
    for(int i=0;i<num;i++){
        scanf("%d %d", &n, &r);
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