#include <stdio.h>
#include <stdlib.h>
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
BIGINT sub(BIGINT a,BIGINT b)
{
    BIGINT R={a.cnt,{0}};
    int t,carry=0;
    for (int i=0;i<a.cnt;i++)
    {
        t=a.v[i]-b.v[i]+carry;
        if (t<0) {t+=10;carry=-1;}
        else carry=0;
        R.v[i]=t;
    }
    if (R.v[a.cnt-1]==0) R.cnt--;
    return R;
}
int max(int a,int b)
{
    if (a>=b) return a;
    else return b;
}
int min(int a,int b)
{
    if (a<b) return a;
    else return b;
}
int main()
{
    char a;
    while ((a=getchar())!=EOF)
    {
        BIGINT A={0,{0}},B={0,{0}};
        char c[501]={0};
        int i=0;
        c[i++]=a;
        while ((c[i++]=getchar())!=' ')
        A.cnt=i;
        if (A.cnt==0) A.cnt++;
        for (int j=0;j<A.cnt;j++)
        {
            A.v[j]=c[i-2]-'0';
            i--;
        }
        i=0;
        while ((c[i++]=getchar())!='\n')
        B.cnt=i;
        for (int j=0;j<B.cnt;j++)
        {
            B.v[j]=c[i-2]-'0';
            i--;
        }
        BIGINT result;
        int flag=0;
        if (A.cnt>B.cnt) result=sub(A,B);
        else if (A.cnt<B.cnt) {result=sub(B,A);flag=1;}
        else
        {
            for (int i=A.cnt-1;i>=0;i--)
            {
                if (A.v[i]>B.v[i]) {result=sub(A,B);break;}
                else if (A.v[i]<B.v[i]) {flag=1;result=sub(B,A);break;}
            }
        }
        if (flag) printf("-");
        for (int j=result.cnt;j>0;j--)
        {
            printf("%d",result.v[j-1]);
        }
        printf("\n");
    }
    return 0;
}
