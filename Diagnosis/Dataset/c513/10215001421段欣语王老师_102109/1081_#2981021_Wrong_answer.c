#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 95

void mul(int *result,int a)
{
    int i,carry=0;
    for(i=0;i<N;i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int result[95]={1},a,n;
        printf("case #%d:\n",i);
        scanf("%d %d",&a,&n);
        for(int j=0;j<n;j++)mul(result,a);
        for(int j=strlen(result)-1;j>=0;j--)
        printf("%d",result[j]);
        printf("\n");
    }
    return 0;
}