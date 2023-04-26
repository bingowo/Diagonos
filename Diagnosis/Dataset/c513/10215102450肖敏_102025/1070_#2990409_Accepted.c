#include <stdio.h>

int main() {
    long long a[21];
    a[0]=0;
    a[1]=2;
    a[2]=4;
    a[3]=7;
    for(int i=4;i<21;i++)
    {
        a[i]=2*a[i-1]-a[i-2]+a[i-3];
    }
    int b;
    scanf("%d",&b);
    while(b != -1)
    {
        printf("%lld\n",a[b]);
        scanf("%d",&b);
    }
    return 0;
}
