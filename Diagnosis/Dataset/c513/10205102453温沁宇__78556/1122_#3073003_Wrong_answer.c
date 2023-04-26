#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    long long n,digit[20];
    for(int i=0;i<T;i++){
        int l=0;
        scanf("%lld",&n);
        if(n==0L){
            printf("0\n");
            continue;
        }
        while(n){
            digit[l++]=n%2333L;
            n/=2333L;
        }
        while(l){
            printf("%lld",digit[--l]);
        }
        printf("\n");
    }


    return 0;
}
