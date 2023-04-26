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
long long N2T(long long a)
{
    return a<9?a:N2T(a/10)*9+a%10;
}
int cmp(const void*a,const void*b)
{
    char* pa=(char*)a,*pa1,*pb=(char*)b,*pb1;
    char a0[21],b0[21],*pa0=a0,*pb0=b0;
    strcpy(a0,pa);strcpy(b0,pb);
    int na=0,nb=0;
    while(*(pa0+1))
    {
        int f=1;
        for(pa1=pa0+1;*pa1;pa1++)
            if(*pa0==1){f=0;break;}
            else if(*pa1==*pa0){*pa1=1;}
        if(f)na++;
        pa0++;
    }
    if(*pa0!=1)na++;
    while(*(pb0+1))
    {
        int f=1;
        for(pb1=pb0+1;*pb1;pb1++)
            if(*pb0==1){f=0;break;}
            else if(*pb1==*pb0){*pb1=1;}
        if(f)nb++;
        pb0++;
    }
    if(*pb0!=1)nb++;
    //printf("%d %d\n",na,nb);
    if(na==nb)return strcmp(pa,pb);
    else return nb-na;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int sn;char s[100][21];
        scanf("%d",&sn);
        for(int j=0;j<sn;j++)scanf("%s",&s[j]);
        qsort(s,sn,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<sn;j++)printf("%s\n",s[j]);
    }
}
