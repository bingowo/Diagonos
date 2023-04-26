#include <stdio.h>
#include <stdlib.h>
typedef struct {int cnt;int v[95];} BIGINT;
BIGINT change(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}
BIGINT mul(BIGINT a,BIGINT b)
{
    BIGINT R={a.cnt+b.cnt,{0}};
    for (int i=0;i<b.cnt;i++)
    {
        int carry=0,t,j;
        for (j=0;j<a.cnt;j++)
        {
            t=a.v[j]*b.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        int k=i+j;
        while (carry)
        {
            t=R.v[k]+carry;
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[a.cnt+b.cnt-1]==0) R.cnt--;
    return R;
}
BIGINT pow1(BIGINT A,int n)
{
    BIGINT r;
    if (n==0) return change(1);
    if (n==1) return A;
    r=pow1(A,n/2);
    r=mul(r,r);
    if (n%2) r=mul(r,A);
    return r;
}
int main()
{
    int N;
    while (scanf("%d",&N))
    {
        BIGINT A=change(N);
        BIGINT result=pow1(A,N);
        printf("%d\n",result.v[result.cnt-1]);
    }
}
