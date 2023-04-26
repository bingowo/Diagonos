#include <stdio.h>
#include <stdlib.h>

int fun(int k, int n)
{
    int sum = 0;
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(n-1-k>=1) sum -= fun(k,n-1-k);
    sum += (2*fun(k,n-1));
    return sum;

}

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    int res = fun(k,n);
    res/=2;
    
    printf("%d",res);

}
