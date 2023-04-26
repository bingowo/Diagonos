#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct{int cnt,v[110];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt && i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp =S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp =T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry) R.v[i++]=carry%10;
    R.cnt=i;
    return R;
}
int main()
{
    char s[105];
    scanf("%s",s);
    BIGINT R={0,{0}};
    int flag=1;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        R.v[R.cnt++]=s[i]-'0';
    }
    int x=1;
    BIGINT I=int2BIG(x);
    while(1)
    {
        R=ADD(R,I);
        int num=0;
        flag=1;
        for(int j=0;j<R.cnt;j++)
        {
            if(R.v[j]==9)
            {
                flag=0;
                break;
            }
            num+=R.v[j];
        }
        if(num%9==0) flag=0;
        if(flag) break;
    }
    for(int j=R.cnt-1;j>=0;j--) printf("%d",R.v[j]);
    return 0;
}
