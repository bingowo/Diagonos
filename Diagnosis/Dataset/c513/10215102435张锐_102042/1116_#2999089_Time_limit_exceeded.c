#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<0) a=-a;
    if(b<0) b=-b;
    int sum=a+b;int temp=1;int i=0;
    if(sum%2==0) i=-1;
    for(;i>=0;i++)
    {
        if(sum<=temp) break;
        temp*=2;
    }
    printf("%d",i);
    return 0;
}

