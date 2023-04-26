#include <stdio.h>
#include <stdlib.h>

#define L 101

typedef struct BIGINT
{
    int flag,len,v[L];
};

struct BIGINT Zero={1,1,{0}};
struct BIGINT One={1,1,{1}};

struct BIGINT add(struct BIGINT A,struct BIGINT B)
{
    int carry=0,cnt=0;
    do{
        A.v[cnt] = A.v[cnt] + B.v[cnt] + carry;
        carry = A.v[cnt]/10;
        A.v[cnt] %= 10;
        cnt++;
    }while(cnt< A.len);
    if(carry!=0)
    {
        A.len++;
        A.v[cnt]=carry;
    }
    return A;
}
void printI(struct BIGINT A)
{
    if(A.flag==-1)printf("-");
    for(int i=A.len-1;i>=0;i--)
        printf("%d",A.v[i]);
    printf("\n");
}

struct BIGINT F(int n)
{
    if(n==0)return Zero;
    if(n==1)return One;
    if(n==2)return One;
    return add(F(n-1),F(n-2));
}

int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;scanf("%d",&t);
        struct BIGINT A=F(t);
        printf("case #%d:\n",i);
        printI(A);
    }
    return 0;
}
