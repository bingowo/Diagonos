#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Max 100000
int main()
{
    int a[Max];
    a[0]=2;
    int t,n;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
            printf("case #%d:\n",j);
            scanf("%d",&n);
    for(int i=0;i<n;i++)
        a[i]=a[i-1]*2;
    printf("%d\n",a[n]);
}
}
