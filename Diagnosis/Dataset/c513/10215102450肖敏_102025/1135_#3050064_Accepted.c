#include <stdio.h>
#include <stdlib.h>

#define N 3000
typedef struct{int cnt, v[N];} BIGINT;

BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt && i< T.cnt;i++)
    {
        int temp=S.v[i]+T.v[i]+carry;
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp=S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp=T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}
int main()
{
    int n;
    scanf("%d",&n);
    BIGINT f0={1,{1}},f1={1,{1}},f2={1,{2}},f3={1,{3}},f4={0};
    if(n<4)
    {
        if(n==1) printf("1\n");
        if(n==2) printf("2\n");
        if(n==3) printf("3\n");
    }
    else
    {
        for(int i=4;i<=n;i++)
        {
            f4=ADD(ADD(f3,f2),f0);
            f0=f1;
            f1=f2;
            f2=f3;
            f3=f4;
        }
        for(int i=f4.cnt-1;i>=0;i--)
        {
            printf("%d",f4.v[i]);
        }
        printf("\n");
    }
    return 0;
}