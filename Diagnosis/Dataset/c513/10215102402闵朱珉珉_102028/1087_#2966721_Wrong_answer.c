#include <stdio.h>
#include <string.h>
typedef struct {int cnt;int v[501];} BIGINT;
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
BIGINT add(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for (i=0;i<S.cnt;i++)
    {
        int t=S.v[i]+T.v[i]+carry;
        carry=t/10;
        R.v[i]=t%10;
    }
    while (i<S.cnt)
    {
        int t=S.v[i]+carry;
        R.v[i++]=t%10;
        carry=t/10;
    }
    while (i<T.cnt)
    {
        int t=T.v[i]+carry;
        R.v[i++]=t%10;
        carry=t/10;
    }
    if (carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}
int Add1(BIGINT A,int k)
{
    int i=k;
    while (i>=0)
    {
        A.v[i]+=1;
        if (A.v[i]<=9) return i;
        A.v[i]=0;
        i--;
    }
    return i;
}
void min(BIGINT A)
{
    int i,j;
    Add1(A,A.cnt-1);
    for (i=1;i<A.cnt;i++)
    {
        if (A.v[i]==A.v[i-1]) break;
    }
    if (i!=A.cnt)
    {
        i=Add1(A,i);
        while (i>0)
        {
            if (A.v[i] != A.v[i-1]) break;
            i=Add1(A,i);
        }
        for (j=i+1;j<A.cnt;j++)
        {
            A.v[j]=(j-i+1)%2;
        }
    }
}
int main()
{
    char line[102];
    int i,T;
    scanf("%d",&T);
    BIGINT result;
    for (int q=0;q<T;q++){
    scanf("%s",line);
    result.cnt=strlen(line);
    for (i=0;i<result.cnt;i++) result.v[i]=line[i]-'0';
    min(result);
    printf("case #%d:\n",q);
    if (result.v[0]!=0) i=0;
    else i=1;
    for (;i<result.cnt;i++)
    {
        printf("%d",result.v[i]);
    }
    printf("\n");
    }
    return 0;
}
