#include <stdio.h>
typedef struct{
int cnt;
int v[10000];
}bigint;
bigint trans(int a)
{
    bigint A = {0,{0}};
    do{
       A.v[A.cnt++] = a%10;
       a /=10;
    }while(a>0);
    return A;
}
bigint mul(bigint a,bigint b)
{
    bigint res = {a.cnt+b.cnt,{0}};
    int i,j;
    for(i = 0;i<a.cnt;i++)
    {
        int t,carry = 0,k;
         for(j = 0;j<b.cnt;j++)
    {
        t = a.v[i]*b.v[j] + carry + res.v[i+j];
        res.v[i+j] = t%10;
        carry = t/10;
    }
    k = i +j;
    while(carry>0)
    {
        t = carry + res.v[k];
        res.v[k] = t%10;
        carry = t/10;
        k++;
    }
    }
    if(res.v[a.cnt+b.cnt-1]==0) res.cnt--;
//    for(i = res.cnt-1;i>=0;i--)
//        printf("%d",res.v[i]);
    return res;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int A,B,N;
        scanf("%d %d %d",&A,&B,&N);
        bigint a,res;
        a = trans(A);
        res = mul(a,a);
        for(j = 2;j<B;j++)
        {
            res = mul(res,a);
        }
        printf("case #%d:\n",i);
        for(j = N-1;j>=0;j--)
            printf("%d",res.v[j]);
        printf("\n");

    }
    return 0;
}
