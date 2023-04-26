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

int main()
{
    char s[100];
    while(scanf("f(x)=%s",s)!=-1)
    {
        getchar();
        char ans[41][41];
        int i,j;
        for(i=0;i<=40;i++)for(j=0;j<=40;j++)ans[i][j]='.';
        for(i=0;i<=40;i++)ans[i][20]='|';
        for(j=0;j<=40;j++)ans[20][j]='-';
        ans[0][20]='^';ans[20][40]='>';ans[20][20]='+';
        int p=0,f=1,a[4]={0,0,0,0};
        do
        {
            int n=0;
            while(s[p]!='x')
            {
                if(s[p]==0){f=0;break;}
                else {p++;n++;}
            }
            s[p]=0;
            if(f==0){a[3]+=atoi(s+p-n);}
            else if(s[p+1]=='^')
                {if(isdigit(s[p+2])){int t=atoi(s+p-n);
                if(t==0)if(s[p-1]=='-')t=-1;
                    else t=1;
                a[3-s[p+2]+'0']=t;p+=3;}}
                else {int t=atoi(s+p-n);if(t==0)if(s[p-1]=='-')t=-1;
                    else t=1;
                    a[2]=t;p++;}
        }while(f);

       // printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
        //printf("%s",s);
        for(i=0;i<=40;i++)
        {
            int x=i-20,t=a[0]*x*x*x+a[1]*x*x+a[2]*x+a[3];
            if(-20<=t&&t<=20)ans[20-t][i]='*';
        }
        for(i=0;i<=40;i++){for(j=0;j<=40;j++)printf("%c",ans[i][j]);printf("\n");}
        printf("\n");
    }
}
