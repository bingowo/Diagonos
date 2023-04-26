#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
typedef struct {long long x,y;unsigned long long d;}M;

unsigned long long lluabs(long long a,long long b)
{
    return a>b?a-b:b-a;
}
typedef struct{int cnt,v[500];}BIGINT;
BIGINT llu2BIG(unsigned long long x)
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
    return *(char*)a<=*(char*)b?-1:1;
}

int main()
{

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a[50];
        a[0]='0';
        int p=0,pos;
        scanf("%s",a+1);
        p=strlen(a)-2;
        for(pos=p;a[pos]>=a[pos+1];pos--);
        for(p++;a[p]<=a[pos];p--);
        char t=a[p];a[p]=a[pos];a[pos]=t;
        //printf("!!%d@%d\n",pos,strlen(a)-pos-1);
        qsort(a+pos+1,strlen(a)-pos-1,sizeof(a[0]),cmp);
        if(a[0]!='0')printf("case #%d:\n%s\n",i,a);
        else printf("case #%d:\n%s\n",i,a+1);

    }

}
