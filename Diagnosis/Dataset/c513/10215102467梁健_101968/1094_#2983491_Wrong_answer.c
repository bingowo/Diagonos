#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct dot
{
    long long dis;
}DOT;
int cmp(const void *a,const void *b)
{
    DOT a1=*(DOT*)a,b1=*(DOT*)b;
    return a1.dis>b1.dis?1:-1;
}

int main()
{
    int n,m;scanf("%d",&n);
    DOT* a=NULL;
    a=(DOT*)malloc(sizeof(DOT)*n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i].dis);
    }
    qsort(a,n,sizeof(DOT),cmp);
    printf("%lld",a[n-1].dis-a[0].dis);
    return 0;
}
