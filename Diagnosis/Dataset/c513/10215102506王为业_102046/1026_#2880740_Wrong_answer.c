//sort\1026.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
short arr[100005];
int cmp(short*x,short*y)
{
    return *x>*y?1:-1;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    for(int in=0;in<n;++in){
        scanf("%hd",&arr[in]);
    }
    qsort(arr,n,sizeof(arr[0]),cmp);
    unsigned ret=0;
    for(int in=1;in<n;in+=2){
        ret+=arr[in]-arr[in-1];
    }
    printf("%u",ret);
}
