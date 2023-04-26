#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct dot
{
    long x;
    long y;
}DOT;
int cmp(const void *a,const void *b)
{
    DOT a1=*(DOT*)a;
    DOT b1=*(DOT*)b;
    long long len1=abs(a1.x)+abs(a1.y);
    long long len2=abs(b1.x)+abs(b1.y);
    if(len1!=len2)return len1>len2?-1:1;
    else if(a1.x!=b1.x)return a1.x>b1.x?1:-1;
    else return a1.y>b1.y?1:-1;
}
int main()
{
    int n;scanf("%d",&n);
    DOT *a=NULL;
    a=(DOT*)malloc(sizeof(DOT)*n);
    for(int i=0;i<n;i++)scanf("%ld %ld",&a[i].x,&a[i].y);
    qsort(a,n,sizeof(DOT),cmp);
    long long dist=2*labs(a[0].x/2.0-a[1].x/2.0)+2*labs(a[0].y/2.0-a[1].y/2.0);
    printf("%lld\n",dist);
    //for(int i=0;i<n;i++)printf("%ld %ld\n",a[i].x,a[i].y);
    int res;
    long long step=1;
    return 0;
}
