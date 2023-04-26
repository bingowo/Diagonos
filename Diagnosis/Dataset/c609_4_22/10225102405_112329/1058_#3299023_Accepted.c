#include<stdio.h>
#define N 102
#define R -2
typedef struct {int sign,d[N],i1,i2;}T;
int iszero(T n) { return n.i1==n.i2 &&n.d[n.i1]==0;}
T dec(T n,int b)
{
    if(b)
        if(!n.sign) n.d[n.i2]--;
        else
        {
            int i;n.d[i=n.i2]++;
            while (n.d[i]>9) n.d[i]=0,n.d[--i]++;
            if(i<n.i1) n.i1--;
        }
    return n;
}
T divr(T n)
{
    int i,t,carry=0; n.sign=!n.sign;
    for(i=n.i1;i<=n.i2;i++) t=n.d[i]&1, n.d[i]=(carry*10+n.d[i])/-R, carry=t;
    if(!iszero(n)&&!n.d[n.i1]) n.i1++;
    return n;
}
void dec2r(T n)
{
    int b;
    if(!iszero(n)) dec2r(divr(dec(n,b=n.d[n.i2]&1))),printf("%ld",b);
}
int main()
{
    T n={0};char s[N+1],*p=s;scanf("%s",s);
    if (*p=='+'||*p=='-')
    {
        if(*p=='-') n.sign=1;
        p++;
    }
    n.i1=n.i2=1; while(*p)n.d[n.i2++]=*p++-'0'; n.i2--;
    if(iszero(n)) printf("0"); else dec2r(n); printf("\n");
    return 0;
}
