#include <stdio.h>
#include <stdlib.h>
typedef struct{
int R;
int H;
int S;}CIR;
int cmp(const void*a,const void *b)
{
    if((*(CIR*)a).S<=(*(CIR *)b).S) return 1;
    else return -1;
}
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    CIR A[n];
    for(i = 0;i<n;i++)
        {
            scanf("%d %d",&A[i].R,&A[i].H);
            A[i].S = 2*A[i].R*A[i].H;
        }
    qsort(A,n,sizeof(CIR),cmp);
    int res[n],maxn = 0;
    for(i = 0;i<n;i++)
    {
        res[i] = A[i].S + A[i].R*A[i].R;
        int count = 1;
        for(j = 0;j<n&&count<m;j++)
        {
            if(i==j||A[j].R>A[i].R) continue;
            res[i] = res[i] + A[j].S;
            count++;
        }
        maxn = maxn>res[i]?maxn:res[i];
    }
     printf("%d %d",maxn,j);
     return 0;
}
