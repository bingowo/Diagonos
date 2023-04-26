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
    for(int i=1;;i++)
    {
        BIGINT I=int2BIG(i);
        BIGINT ANS=ADD(R,I);
        int num=0;
        flag=1;
        for(int j=0;j<ANS.cnt;j++)
        {
            if(ANS.v[j]==9)
            {
                flag=0;
                break;
            }
            num+=ANS.v[j];
        }
        if(num%9==0) flag=0;
        if(flag)
        {
            for(int j=ANS.cnt-1;j>=0;j--)
                printf("%d",ANS.v[j]);
            break;
        }
    }
    return 0;
}
