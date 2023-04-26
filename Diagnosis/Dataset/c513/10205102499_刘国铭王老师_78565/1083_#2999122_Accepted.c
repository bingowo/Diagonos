#include <stdio.h>

struct BIGINT
{
    int cnt,v[3000];
};

int main()
{
    int T;
    scanf("%d",&T);
    int i,j,carry,t;
    for(int k=0;k<T;k++)
    {
    struct BIGINT R={1,{1}};
    int N,res=0;
    scanf("%d",&N);
    for(i=2;i<=N;i++)
    {
        carry=0;
        for(j=0;j<R.cnt;j++)
        {
            t=R.v[j]*i+carry;
            R.v[j]=t%10;
            carry=t/10;
        }
        while(carry>0)
        {
            R.v[R.cnt++]=carry%10;
            carry/=10;
        }
    }
    while(R.v[res]==0)
        ++res;
    printf("case #%d:\n",k);
    printf("%d\n",res);
    res=0;
    }
    return 0;
}
