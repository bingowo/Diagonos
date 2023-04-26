#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 95
typedef struct { int cnt,v[N]; } BIGINT ;
BIGINT int2BIG(int x)
{
    BIGINT R= {0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}
BIGINT pow(BIGINT a, int n)
{
    BIGINT r;
    if (n==0) return int2BIG(1);
    if (n==1) return a;
    r=pow(a, n/2);
    r=mul(r,r);
    if (n%2) r=mul(r, a);
    return r;
}

int main(){
    int t,a,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&a,&n);
        pow(int2BIG(a),n);
    }
}