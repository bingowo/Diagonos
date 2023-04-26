#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long int n;
        scanf("%d",&n);
        int a[100],j=0;
        while(n>0)
        {
            a[j]=n%2333;
            n/=2333;
            j++;
        }
        for(int k=j-1;k>0;k--)
            printf("%d ",a[k]);
        printf("%d\n",a[0]);
    }
    return 0;
}