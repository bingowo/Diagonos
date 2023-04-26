//math\1071.c

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

#define MOD 10007
int a,b;
int data[1002][1002];

int getans(int n,int m)
{
    memset(data,0,1002*sizeof(data[0]));
    int tem=1;
    for(int in=0;in<=n;++in){
        data[in][0]=tem;
        tem*=a;
        tem%=MOD;
    }
    tem=1;
    for(int im=0;im<=m;++im){
        data[0][im]=tem;
        tem*=b;
        tem%=MOD;
    }
    //begin to initialize data area;
    for(int im=1;im<=m;++im){
        for(int in=1;in<=n;++in){
            data[in][im]=(data[in-1][im]%MOD*a+data[in][im-1]%MOD*b)%MOD;
        }
    }
    return data[n][m];
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        a%=MOD;
        b%=MOD;
        printf("%d\n",getans(n,m));
    }
}