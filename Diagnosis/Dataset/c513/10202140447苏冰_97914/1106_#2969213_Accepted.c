#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define W 1000000007
typedef struct{int cnt,v[1100];}BIGINT;
BIGINT int2BIG(long long x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return R;
}
BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j;
        int carry=0;
        for(j=0;j<S.cnt;j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while(carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}
BIGINT MOD(BIGINT N)
{
    long long xx=0;
    for(int i=N.cnt-1;i>=0;i--)
    {
        xx=(xx*10+N.v[i])%W;
    }
    BIGINT XX=int2BIG(xx);
    return XX;
}
int main()
{
    char s[1010];
    scanf("%s",s);
    long long x=1;
    int len=strlen(s);
    if(len==1) x=1;
    else if(len==2)
    {
        if(s[0]==s[1]) x=1;
        else x=4;
    }
    else
    {
        if(s[0]==s[1]) x=1;
        else x=2;
        if(s[len-1]==s[len-2]) x=x*1;
        else x=x*2;
    }
    BIGINT X=int2BIG(x);
    for(int i=1;i<len-1;i++)
    {
        int a=s[i-1]-'a';
        int b=s[i]-'a';
        int c=s[i+1]-'a';
        int m[30]={0};
        long long cnt=0;
        if(m[a]==0)
        {
            m[a]=1;cnt++;
        }
        if(m[b]==0)
        {
            m[b]=1;cnt++;
        }
        if(m[c]==0)
        {
            m[c]=1;cnt++;
        }
        BIGINT CNT=int2BIG(cnt);
        X=mul(MOD(X),MOD(CNT));
    }
    X=MOD(X);
    for(int i=X.cnt-1;i>=0;i--) printf("%d",X.v[i]);
    return 0;
}
