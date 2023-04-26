#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long a,b[100],c;
    int n,m=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        m=0;
        scanf("%lld",&a);
        if(a==0) {
            printf("0\n");
            continue;
        }
        while(a){
        b[m] = a%2333;
        m++;
        a = a/2333;
        }
        m--;
        for(;m>=0;m--){
            printf("%lld ",b[m]);
        }
        printf("\n");
    }
    return 0;
}
