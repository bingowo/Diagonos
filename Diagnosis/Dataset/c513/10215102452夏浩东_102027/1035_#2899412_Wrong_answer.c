#include <stdio.h>
#include <stdlib.h>
struct M
{
    long long int R;
    long long int H;
};
int cmp(const void *a,const void *b)
{
    struct M* A=(struct M*)a;
    struct M* B=(struct M*)b;
    long long int S1=2*(A->H)*(A->R);
    long long int S2=2*(B->H)*(B->R);
    if(S1>=S2) return -1;
    else return 1;
}
int main()
{
    int maxnum=0;
    long long int n=0,m=0,max=0;
    struct M L[1000];
    scanf("%lld %lld",&n,&m);
    for(int k=0;k<n;k++)
    {
        scanf("%lld %lld",&L[k].R,&L[k].H);
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
    for(int k=0;k<m-1;k++)
	{
		left+=2*L[k].R*L[k].H;
	}
    printf("%lld",left+max);
    return 0;
}