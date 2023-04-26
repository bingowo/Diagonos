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
void DIV2(BIGINT *n)
{
    int carry=0;
    if (n->v[n->cnt-1]<2)
    {
        n->cnt--;
        carry=1;
    }
    for (int i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
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
int main()
{
    char line[102];
    int i;
    BIGINT n;
    scanf("%s",line);
    n.cnt=strlen(line);
    for (i=0;i<n.cnt;i++) n.v[i]=line[n.cnt-i-1]-'0';
    int bin[334],cnt=0;
    while (n.cnt>0)
    {
        bin[cnt++]=n.v[0]%2;
        DIV2(&n);
    }
    BIGINT result=change(0);
    for (i=0;i<cnt;i++)
    {
        result=mul(result,change(2));
        result=add(result,change(bin[i]));
    }
    if (n.cnt==0) n.cnt++;
    for (i=n.cnt-1;i>=0;i--)
    {
        printf("%d",n.v[i]);
    }
    printf("\n");
    return 0;
}
