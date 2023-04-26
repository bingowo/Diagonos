#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        long long n;
        scanf("%lld",&n);
        if (n==0) {
            printf("\n");
            continue;
        }
        int a[10010];
        int i=0;
        while (n!=0){
            a[i]=n%2333;
            n=n/2333;
            i++;
        }
        i--;
        for (int j=i;j>=0;j--){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 0;
}
