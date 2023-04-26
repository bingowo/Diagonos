#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    int a[1001];

    memset(a,0,sizeof(a));
    a[0]=1;
    for (int i=4;i>=1;i--)
        for (int j=i;j<=1000;j++)
            a[j]+=a[j-i];


    for (int i=0;i<t;i++){
            int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }


    return 0;
}