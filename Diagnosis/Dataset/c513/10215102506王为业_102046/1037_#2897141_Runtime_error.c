//sort\1037.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
ULL dataarr[1000009];

int cmp(ULL*x,ULL*y)
{
    return *x<*y?1:-1;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n,m;
    scanf("%d %d",&n,&m);
    for(int in=0;in<n;++in){
        scanf("%llu",&dataarr[in]);
    }
    qsort(dataarr,n,sizeof(dataarr[0]),cmp);
    ULL res=-1;
    ULL temsum=0;
    ULL tres=0;
    for(int im=1;im<m;++im)//get sum of upper m-1 nums
        temsum+=dataarr[im];
    for(int i=0;i<n-m;++i){
        tres=(m-1)*dataarr[i]-temsum;
        if(tres<res)res=tres;
        temsum-=dataarr[i+1];
        temsum+=dataarr[i+m];
    }
    tres=(m-1)*dataarr[n-m]-temsum;
    if(tres<res)res=tres;
    printf("%llu",res);
}
