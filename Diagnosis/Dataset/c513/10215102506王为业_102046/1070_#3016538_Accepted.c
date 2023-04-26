//dsum\1070.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/

#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int dp[22]={0,2,4,7,12};

int getans(int len)
{
    if(dp[len]==0){
        dp[len]=getans(len-1)*2-getans(len-2)+getans(len-3);
    }
    return dp[len];
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int len;
    while(scanf("%d",&len),len!=-1){
        printf("%d\n",getans(len));
    }
}