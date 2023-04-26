#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
typedef struct{int cnt,v[334];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}
BIGINT MUL(BIGINT S,BIGINT T)
{
    BIGINT R0={0,{0},1};
    //if()
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j,carry=0;
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
    if(R.v[S.cnt+T.cnt-1]==0)R.cnt--;
    return R;
}
int main()
{
    char s[2000]={};
    s[0]=1;
    scanf("%s",s+1);
    int l=strlen(s);//printf("!%s\n",s);
    s[0]=s[1];s[l]=s[l-1];
    BIGINT ans=int2BIG(1);
    for(int i=1;i<l;i++)
    {
        int t=1;
        if(s[i]!=s[i-1])t++;
        if(s[i]!=s[i+1])t++;
        ans=MUL(ans,int2BIG(t));
        //printf("!%d\n",l);
    }
    for(int i=ans.cnt-1;i>=0;i--)printf("%d",ans.v[i]);
}
