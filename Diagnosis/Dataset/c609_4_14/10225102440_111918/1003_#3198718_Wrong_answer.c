#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int t,i;
    scanf("%lld",&t);
    long long int a[t],b[t][10],x,j,k;
    for(i=0;i<t;i++) scanf("%lld",&a[i]);
    for(i=0;i<t;i++){
            x=a[i];
            j=0;
        while(x){
            b[i][j]=x%2333;
            x =x/2333;
            j++;
        }
        while(--j>=0) printf("%lld ",b[i][j]);
        printf("\n");
    }
    return 0;
}
