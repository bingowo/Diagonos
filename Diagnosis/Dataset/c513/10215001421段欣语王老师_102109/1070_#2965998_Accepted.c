#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int d00[21],d01[21],d1[21];
    d00[1]=d1[1]=1;
    d01[1]=0;
    d00[2]=d01[2]=1;
    d1[2]=2;
    for(n=3;n<=20;n++)
    {
        d00[n]=d00[n-1]+d01[n-1];
        d01[n]=d1[n-1];
        d1[n]=d00[n-1]+d1[n-1];
    }
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)break;
        printf("%d\n",d00[n]+d01[n]+d1[n]);
    }
    return 0;
}