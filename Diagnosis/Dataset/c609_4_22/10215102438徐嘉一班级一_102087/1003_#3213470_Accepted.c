#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a[18];
    long long int n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%lld",&n);
        int k=0;
        do{
            a[k++]=n%2333;
            n/=2333;
        }while(n);
        a[k+1]='\0';
        for(k=k-1;k>=0;k--)
        {
            printf("%d",a[k]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
