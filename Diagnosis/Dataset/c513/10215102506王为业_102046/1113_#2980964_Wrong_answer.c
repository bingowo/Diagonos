//math\1113.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int k;
    int n;
    scanf("%d%d",&k,&n);

    unsigned long long arr[101]={0,0,1};
    //begin with 1 pos
    int nowlen=2;
    int nowpos=2;
    unsigned long long nownum=1;
    while(nowpos<=n){
        ++nowpos;//----------------------
        arr[nowpos]=nownum;
        if(nowlen==k){
            nownum-=arr[nowpos-k+1];
        }else{
            ++nowlen;
        }
        nownum+=arr[nowpos];

    }
    printf("%llu",arr[n]);
}

