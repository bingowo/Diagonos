#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int n;
    int res=0,mid=0,num=0;
    scanf("%d",&n);
    int A[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        num+=1;
    }
    qsort(A,num,sizeof(A[0]),cmp);
    for(int j=0;j<n;j=j+2)
    {
        mid=abs(A[j]-A[j+1]);
        res+=mid;
    }
    printf("%d",res);
    return 0;
}
