#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%d",&n);
        int k=0,a[100];
        do{
            a[k++]=n%2333;
            n/=2333;
        }while(n);
        for(k--;k>=0;k--)
            printf("%d ",a[k]);
        printf("\n");
    }
    return 0;
}
