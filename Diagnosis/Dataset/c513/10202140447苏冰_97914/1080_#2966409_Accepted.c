#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 335
typedef struct{int cnt,v[N];}BIGINT;
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
void DIV2(BIGINT *n)
{
    int carry=0;
    if((*n).v[(*n).cnt-1]<2)
    {
        (*n).cnt--;
        carry=1;
    }
    for(int i=(*n).cnt-1;i>=0;i--)
    {
        int t=carry*10+(*n).v[i];
        (*n).v[i]=t/2;
        carry=t%2;
    }
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
int main()
{
   int T;
   scanf("%d",&T);
   char s[110];
   for(int cas=0;cas<T;cas++)
   {
       scanf("%s",s);
       BIGINT n={0,{0}};
       for(int i=strlen(s)-1;i>=0;i--)
       {
           n.v[n.cnt++]=s[i]-'0';
       }
       int bin[335];
       int cnt=0;
       while(n.cnt>0)
       {
           bin[cnt++]=n.v[0]%2;
           DIV2(&n);
       }
       BIGINT X=int2BIG(2);
       BIGINT ANS={0,{0}};
       for(int i=0;i<cnt;i++)
       {
           BIGINT TEMP=int2BIG(bin[i]);
           ANS=ADD(mul(ANS,X),TEMP);
       }
       int i;
       printf("case #%d:\n",cas);
       if(s[0]=='0' && strlen(s)==1) printf("0");
       else
       {
           for(i=ANS.cnt-1;ANS.v[i]==0;i--);
           for(;i>=0;i--) printf("%d",ANS.v[i]);
       }
       printf("\n");
   }
   return 0;
}
