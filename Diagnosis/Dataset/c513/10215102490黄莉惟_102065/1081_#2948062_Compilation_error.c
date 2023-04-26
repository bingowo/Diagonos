#include<stdio.h>
#include <stdlib.h>
#include<string.h>
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

BIGINT mul(BIGINT S, BIGINT T)
{
    BIGINT R= {S.cnt+T.cnt,{0}};
    for (int i=0; i<T.cnt; i++)
    {
         int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--; 
    return R;
}
int main(){
    int t,a,n,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&a,&n);
        printf("%s",mul(BIGINT a, BIGINT n));
    }
}