#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct dot
{
    long long x,y,dis;
}DOT;
int cmp(const void *a,const void *b)
{
    DOT a1=*(DOT*)a;
    DOT b1=*(DOT*)b;
    if(a1.dis!=b1.dis)return a1.dis>b1.dis?1:-1;
    else if(a1.x!=b1.x)return a1.x>b1.x?1:-1;
    else return a1.y>b1.y?1:-1;
}
int main()
{
    long long A,B;scanf("%lld %lld",&A,&B);
    int n;scanf("%d",&n);
    DOT*a=NULL;
    a=(DOT*)malloc(sizeof(DOT)*n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].dis=llabs(A-a[i].x)>llabs(B-a[i].y)?llabs(A-a[i].x):llabs(B-a[i].y);
    }
    qsort(a,n,sizeof(DOT),cmp);
    printf("%lld\n",a[0].dis);
    printf("%lld %lld",a[0].x,a[0].y);
    return 0;
}
