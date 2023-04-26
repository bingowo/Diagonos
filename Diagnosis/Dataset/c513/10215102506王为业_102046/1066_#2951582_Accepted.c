//DP\1066.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
int n;
int dp_build_min[110][22];
int ways(int p,int m)
{
    if(dp_build_min[p][m]==-1){
        if(n==p){
            dp_build_min[p][m]=ways(n-1,m-1);
        }else if(p==1){
            dp_build_min[p][m]=ways(2,m-1);
        }else{
            dp_build_min[p][m]=ways(p-1,m-1)+ways(p+1,m-1);
        }
    }
    return dp_build_min[p][m];
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp_build_min,-1,110*sizeof(dp_build_min[0]));
        int p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        for(int i=0;i<110;++i)
            dp_build_min[i][0]=0;
        dp_build_min[t][0]=1;
        printf("%d\n",ways(p,m));
    }
}
