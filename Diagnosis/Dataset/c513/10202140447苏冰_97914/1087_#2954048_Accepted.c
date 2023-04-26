#include<stdio.h>
#include<string.h>
#define N 110
typedef struct{int cnt,v[N];}BIGINT;
int flag=0;
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
int solve(BIGINT R)
{
    for(int i=R.cnt-1;i>=1;i--)
    {
        if(R.v[i]==R.v[i-1])
        {
            flag=0;return i-1;
        }
    }
    flag=1;return 1;
}
int main()
{
	int T;
	scanf("%d",&T);
	char s[110];
	for(int cas=0;cas<T;cas++)
    {
        flag=0;
        BIGINT A={0,{0}};
        scanf("%s",s);
        for(int i=strlen(s)-1;i>=0;i--) A.v[A.cnt++]=s[i]-'0';
        printf("case #%d:\n",cas);
        BIGINT ANS=A;
        int x=1;
        BIGINT I=int2BIG(x);
        ANS=ADD(ANS,I);
        while(1)
        {
            int m=solve(ANS);
            if(flag==1) break;
            int xx=ANS.v[m];
            BIGINT W={0,{0}};
            if(xx!=9)
            {
                for(int j=0;j<m;j++) W.v[W.cnt++]=0;
                W.v[W.cnt++]=xx+1;
            }
            else
            {
                for(int j=0;j<=m;j++) W.v[W.cnt++]=0;
                W.v[W.cnt++]=1;
            }
            for(int j=m;j>=0;j--) ANS.v[j]=0;
            ANS=ADD(ANS,W);
        }
        for(int j=ANS.cnt-1;j>=0;j--) printf("%d",ANS.v[j]);
        printf("\n");
    }
    return 0;
}
