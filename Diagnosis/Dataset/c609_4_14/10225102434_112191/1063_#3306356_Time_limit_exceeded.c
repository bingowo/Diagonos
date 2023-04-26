#include <stdio.h>
#include <stdlib.h>

long long int f(long long int x)
{
    if(x==2||x==1)return x;
    if(x==3)return 4;
    if(x==4)return 8;

    return(f(x-1)+f(x-2)+f(x-3)+f(x-4));
}
int main()
{
    int n;
    scanf("%d",&n);
    int i ;
    long long int x;
    for(i = 0;i<n;i++){
        scanf("%lld",&x);
        printf("case #%d:\n%lld\n",i,f(x));
    }
    return 0;

}

