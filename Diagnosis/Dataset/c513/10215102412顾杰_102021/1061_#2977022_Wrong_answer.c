#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{int cnt,v[334];}BIGINT;
typedef struct{char s[16];unsigned long long n;}WORD;
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
int cmp(const void*a,const void*b)
{
    WORD pa=*(WORD*)a,pb=*(WORD*)b;
    if(pa.n!=pb.n)return pa.n<pb.n?-1:1;
    else return strcmp(pa.s,pb.s);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    WORD a[10000];
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
        int tab[1000];
        for(int j=0;j<1000;j++)tab[j]=-1;
        tab[a[i].s[0]]=1;
        int k=1,m=2;
        while(a[i].s[k]==a[i].s[0])k++;
        tab[a[i].s[k++]]=0;
        for(;a[i].s[k];k++)if(tab[a[i].s[k]]==-1)tab[a[i].s[k]]=m++;
        a[i].n=0;
        for(k=0;a[i].s[k];k++){a[i].n*=m;a[i].n+=tab[a[i].s[k]];}
        //printf("%lld!!!\n",a[i].n);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)printf("%s\n",a[i].s);

}
