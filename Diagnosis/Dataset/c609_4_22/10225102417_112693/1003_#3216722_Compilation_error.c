#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,r,i;
    int t;
    scanf("%d",&t);
    for(i=;i<t;i++){
        int k=0,a[33];
        scanf("%lld",&x);
        do{
            r=x%2333;
            a[k++]=r;
            x=x/2333;
        }while(x);
        for(k=k-1;k!=-1;k--){
            printf("%lld",a[k]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
