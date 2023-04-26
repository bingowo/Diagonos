#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    int t;
    scanf("%d",&t);
    int m,n;
    for (int i=0;i<t;i++){
        scanf("%d%d",&m,&n);
        long long k=1;
        for (int j=1;j<=n;j++){
            k=k*(m-j+1)/j;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",k);
    }
}
