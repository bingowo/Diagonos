#include <stdio.h>
#include <stdlib.h>
#define N 10000

int main()
{
    int n,a[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    for(int k=0;k<n;k++)
    {
        int cnt=0,c[N];
        while(a[k]>0)
        {
            c[cnt]=a[k]%2333;
            a[k]=a[k]/2333;
            cnt++;
        }
        for(int i=(cnt-1);i>=0;i--) printf("%d ",c[i]);
        printf("\n");
    }
    return 0;
}