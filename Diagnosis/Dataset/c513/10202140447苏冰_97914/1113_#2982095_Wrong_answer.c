#include <stdio.h>
#include <string.h>
int a[120];
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    a[9]=1;
    for(int i=10;i<n+8;i++)
    {
        for(int j=i-1;j>=i-k;j--)
        {
            a[i]=a[i]+a[j];
        }
    }
    printf("%d\n",a[n+8-1]);
    return 0;
}
