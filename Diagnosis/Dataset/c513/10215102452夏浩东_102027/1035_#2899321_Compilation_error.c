#include <stdio.h>
#include <stdlib.h>
typedef struct M{
    int R;
    int H;
};
int cmp(const void *a,const void *b)
{
    struct M* A=(M*)a;
    struct M* B=(M*)b;
    long long int S1=2*(A->H)*(A->R);
    long long int S2=2*(B->H)*(B->R);
    if(S1>=S2) return -1;
    else return 1;
}
int main()
{
    int n=0,m=0,maxnum=0;
    long long int max=0;
    struct M L[1000];
    scanf("%d %d",&n,&m);
    for(int k=0;k<n;k++)
    {
        scanf("%d %d",&L[k].R,&L[k].H);
    }
    for(int k=0;k<n;k++)
    {
        if((L[k].R*L[k].R+2*L[k].R*L[k].H)>max)
        {
            max=L[k].R*L[k].R+2*L[k].R*L[k].H;
            maxnum=k;
        }
    }
    L[maxnum].R=0;
    L[maxnum].H=0;
    qsort(L,n,sizeof(struct M),cmp);
    long long int left=0;
    for(int k=0;k<m-1;k++) left+=2*L[k].R*L[k].H;
    printf("%lld",left+max);
    return 0;
}