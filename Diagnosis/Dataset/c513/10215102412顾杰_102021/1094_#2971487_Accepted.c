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
int cmp(const void*a,const void*b)
{
    int*pa=(int*)a,*pb=(int*)b,i;
    for(i=0;i<=120;i++)
    {
        if(*(pa+i)!=*(pb+i))break;
    }
    if(i==121)return 0;
    else return -*(pa+i)+*(pb+i);
}
int main()
{
    int a[50][121]={0},n,i,carry=0;
    char s[122];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=strlen(s)-1,k=120;j>=0;j--,k--)
        {
            if(s[j]=='-'){for(int y=k+1;y<=120;y++)a[i][y]*=-1;}
            else a[i][k]=s[j]-'0';
            }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=120;i>=0;i--)
    {
        a[0][i]=(a[0][i]-a[n-1][i]+carry);
        if(a[0][i]<0){a[0][i]+=10;carry=-1;}
        else if(a[0][i]>=10){a[0][i]-=10;carry=1;}
        else carry=0;
    }
    i=0;
    while(a[0][i]==0)i++;
    for(;i<=120;i++)printf("%d",a[0][i]);
}
