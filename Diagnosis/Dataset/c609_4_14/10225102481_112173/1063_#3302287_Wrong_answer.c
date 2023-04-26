#include <stdio.h>
#include <stdlib.h>

typedef struct{int cnt,v[1000];}bigint;

bigint MUL(bigint R,int a)
{
    int carry=0,j,t;
    for(j=0;j<R.cnt;j++)
    {
        t=R.v[j]*a+carry;
        R.v[j]=t%10;
        carry=t/10;
    }
    while(carry>0)
    {
        R.v[R.cnt++]=carry%10;
        carry/=10;
    }
    return R;
}

void printbigint(bigint R)
{
    int i;
    for(i=R.cnt-1;i>=0;i--)printf("%d",R.v[i]);
}

int main()
{
   int T;
   scanf("%d",&T);
   
   for(int I=0;I<T;I++)
   {
       int a,n,i;
       bigint ans={1,{1}};
       printf("case #%d:\n",I);
       scanf("%d%d",&a,&n);
       for(i=0;i<n;i++)ans=MUL(ans,a);
       printbigint(ans);printf("\n");
   }
   
   return 0;
}
