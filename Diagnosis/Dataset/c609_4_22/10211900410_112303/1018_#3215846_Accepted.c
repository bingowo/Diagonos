#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 int cmp(const void * a,const void * b)
{
    return (*(int*)a-*(int*)b);
}

int main()
{
    int n;
    scanf("%d\n",&n);
    int L[n],i,j;
    for(i=0;i<n;i++){
        scanf("%d",&L[i]);
    }
    qsort(L,i,sizeof(int),cmp);
    int sum=0;
    for(j=0;j+1<n;j=j+2){
        sum+=abs(L[j+1]-L[j]);
    }
    //if(j!=i-1) sum+=abs(L[j]);
    printf("%d",sum);
    return 0;
}