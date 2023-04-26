#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b
struct record{
long long int x;
long long int y;
long long int cd;
};
int cmp(const void *a,const void *b)
{
    struct record A = *((struct record*)a),B = *((struct record*)b);
    if(A.cd>B.cd) return 1;
    else if(A.cd==B.cd&&A.x>B.x) return 1;
    else if(A.cd==B.cd&&A.x==B.x&&A.y>B.y) return 1;
    else return -1;
}
int main()
{
    long long x0,y0;
    scanf("%lld %lld",&x0,&y0);
    int n,i;
    scanf("%d",&n);
    struct record A[n];
    for(i = 0;i<n;i++)
    {
        scanf("%lld %lld",&A[i].x,&A[i].y);
        A[i].cd = max(llabs(A[i].x-x0),llabs(A[i].y-y0));
    }
    qsort(A,n,sizeof(struct record),cmp);
    printf("%lld\n%lld %lld",A[0].cd,A[0].x,A[0].y);
    return 0;

}
