#include <stdio.h>
#include <stdlib.h>
typedef struct {int cnt,v[95]} BIGINT;
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
    int a,b;

    {
        BIGINT A,B;
        char c;
        int i=0;
        while ((c=getchar())!=' ') {A.v[i++]=(int)c;}
        i=0;
        while ((c=getchar())!='\n') {B.v[i++]=(int)c;}
        BIGINT result=sub(A,B);
        if (a<b) printf('-');
        for (int j=result.cnt-1;j>=0;j--)
        {
            printf("%d",result.v[j]);
        }
        printf("\n");
    }
    return 0;
}
