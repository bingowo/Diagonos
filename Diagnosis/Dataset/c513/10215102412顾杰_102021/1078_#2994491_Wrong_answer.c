#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
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
BIGINT mul(BIGINT S,BIGINT T)
{
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
    return *(int*)a-*(int*)b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int a[2000]={0},b[2000][2]={0},n,s;
void pour(int pos)
{
    //for(int i=1;i<=n;i++){printf("%d",a[i]);if(b[i][0]!=0)printf("+%d/%d",b[i][0],b[i][1]);printf(" ");}
    //printf("\ns=%d,pos=%d\n",s,pos);
     while(s>0){
    int lv=0,lp,rp,rv=0,i;
    for(i=pos-1;a[i]<=a[pos];i--)lv+=a[pos]-a[i];
    lp=i+1;
    for(i=pos+1;a[i]<=a[pos];i++)rv+=a[pos]-a[i];
    rp=i-1;
    if(lv+rv==0)
    {
        //printf("!!%d\n",s);
        int m=min(a[lp-1],a[rp+1]),v=(m-a[pos])*(rp-lp+1),l=rp-lp+1,g=gcd(l,s%l),ap=a[pos];//printf("%d\n",v);
        if(v>=s){
                for(i=lp;i<=rp;i++){a[i]=ap+s/l;b[i][0]=s%l/g;b[i][1]=l/g;}
                s=0;
                }
        else {for(i=lp;i<=rp;i++)a[i]=m;s-=v;}
    }
    else if(lv+rv<=s){for(i=lp;i<=rp;i++)a[i]=a[pos];s-=lv+rv;}//printf("%d\n",lv+rv);}
    else
    {
        //printf("!!%d\n",s);
        if(lv<=s/2){for(i=lp;i<pos;i++)a[i]=a[pos];s-=lv;
                    for(i=pos;a[i]>=a[i+1];i++);pour(i);}
        else if(rv<=s/2){for(i=rp;i>pos;i--)a[i]=a[pos];s-=rv;
                          for(i=pos;a[i]>=a[i-1];i--);pour(i);}
        else {for(i=pos;a[i]>=a[i+1];i++);s/=2;pour(i);for(i=pos;a[i]>=a[i-1];i--);pour(i);s=0;}

    }
    }

}
int main()
{
    int pos,i;
    scanf("%d%d%d",&n,&s,&pos);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=1e6+1;a[n+1]=1e6+1;
    //
   pour(pos);

    for(i=1;i<=n;i++){printf("%d",a[i]);if(b[i][0]!=0)printf("+%d/%d",b[i][0],b[i][1]);printf(" ");}
}
