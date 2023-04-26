#include <stdio.h>
#include <stdlib.h>
long long int a[51];
long long stairs(int m)
{
    if(a[m]!=0)return a[m];
    else {a[m]=stairs(m-1)+stairs(m-2)+stairs(m-3)+stairs(m-4);return a[m];}
}
int main()
{
    int n;
    scanf("%d",&n);
    a[1]=1;a[2]=2;a[3]=4;a[4]=8;
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        printf("case #%d:\n",i);
        printf("%lld\n",stairs(m));
    }
    return 0;
}
