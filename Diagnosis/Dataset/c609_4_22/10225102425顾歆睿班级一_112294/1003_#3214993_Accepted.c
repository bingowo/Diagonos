#include<stdio.h>
#include<math.h>
void trans(long long n)
{
    if(n>0){
        trans(n/2333);
        printf("%d ",n%2333);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        long long n;
        scanf("%lld",&n);
        if(n==0){
            printf("0");
        }
        else trans(n);
        printf("\n");
    }
    return 0;
}
