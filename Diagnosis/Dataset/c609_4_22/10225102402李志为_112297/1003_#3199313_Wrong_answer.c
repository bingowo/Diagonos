#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long a,b,c;
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        while(a){
        b = a%2333;
        a = a/2333;
        printf("%d ",b);
    }
    }
    return 0;
}
