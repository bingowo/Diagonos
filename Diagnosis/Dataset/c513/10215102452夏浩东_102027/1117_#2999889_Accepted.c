#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long int L[1000000][3];
int cmp(const void *a,const void *b)
{
    long long int* A = (long long int*)a;
    long long int* B = (long long int*)b;
    if(A[2]==B[2]){
        if(A[0]==B[0]){
            if(A[1]>B[1]) return 1;
            else return -1;
        }else{
            if(A[0]>B[0]) return 1;
            else return -1;
        }
    }else{
        if(A[2]>B[2]) return 1;
        else return -1;
    }
}
int main()
{
    long long int x=0,y=0;
    int n=0,i=0;
    scanf("%lld %lld",&x,&y);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&L[i][0],&L[i][1]);
        L[i][2]=llabs(L[i][0]-x)>llabs(L[i][1]-y)?llabs(L[i][0]-x):llabs(L[i][1]-y);
    }
    qsort(L,i,sizeof(L[0]),cmp);
    printf("%lld\n",L[0][2]);
    printf("%lld %lld",L[0][0],L[0][1]);
    return 0;
}