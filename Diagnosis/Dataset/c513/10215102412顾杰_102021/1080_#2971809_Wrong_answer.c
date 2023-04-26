#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
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
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt&&i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
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
void DIV2(BIGINT *n)
{
    int carry=0,i;
    if(n->v[n->cnt-1]<2){n->cnt--;carry=1;}
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}
int main()
{
    int m,i;
    BIGINT n;
    char s[102];
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%s",s);
        n.cnt=strlen(s);
        for(int j=0;j<n.cnt;j++)n.v[j]=s[n.cnt-i-1]-'0';
        int bin[334],cnt=0;
        while(n.cnt>0)
        {
            bin[cnt++]=n.v[0]%2;
            DIV2(&n);
        }
        BIGINT n0={0,{0}};
        for(int j=0;j<cnt;j++)
        {n0=ADD(n0,n0);
        //    printf("%d",bin[j]);
            if(bin[j])n0=ADD(n0,int2BIG(1));

        }
        printf("case #%d:\n",i);
        if(n0.cnt==0)n0.cnt++;
        for(int j=n0.cnt-1;j>=0;j--)printf("%d",n0.v[j]);
        printf("\n");
    }

}
