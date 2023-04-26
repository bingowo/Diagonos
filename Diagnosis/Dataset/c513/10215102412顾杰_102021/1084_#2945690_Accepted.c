#include <stdio.h>
#include <math.h>

int main()
{
    int i,x,j,b;
    scanf("%d",&x);
    int a[x];
    for(i=0;i<x;i++){a[i]=1;
        scanf("%d",&b);
        for(j=0;j<b;j++)a[i]*=2;
    }
    for(i=0;i<x;i++)
    printf("case #%d:\n%d\n",i,a[i]);
    return 0;
}