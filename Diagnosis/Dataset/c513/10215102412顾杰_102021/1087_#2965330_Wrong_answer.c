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
int main()
{
    int n,i,j,k;
    char c;
    BIGINT a={0,{0}},l=int2BIG(1);
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        k=0;
        while((c=getchar())!='\n')a.v[k++]=c-'0';
        a.cnt=k;
        k--;
       a=ADD(a,l);
       do
        {
            int f=0;
            for(j=a.cnt-1;j>=1;j--)if(a.v[j-1]==a.v[j])
                {
                    BIGINT l0={j,{0}};
                    l0.v[j-1]=1;
                    a=ADD(a,l0);
                    for(int m=0;m<j-1;m++)a.v[m]=0;
                    f=1;break;}
            if(f){continue;}
            if(j<=1)break;
        }while(1);
        printf("case #%d:\n",i);
        for(j=a.cnt-1;j>=0;j--)printf("%d",a.v[j]);
        printf("\n");
    }

}
