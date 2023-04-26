#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int n;
void s(int n)
{
    long long res=0;
    for(int i=n;i>=0;i--){
        res+=solve2(i);
    }
    printf("%lld\n",res);
}
int solve2(int i)
{
    int r=0;
    for(int j=0;2*j<=n-i;j++)
        r+=solve3(j,i);
    return r;
}
int solve3(int j,int i)
{
    int r=0;
    for(int m=0;3*m<=n-i-2*j;m++)
        r+=solve4(m,j,i);
    return r;
}
int solve4(int m,int j,int i)
{
    int r=0;
    for(int p=0;4*p<=n-i-2*j-3*m;p++)
        if(4*p+3*m+2*j+i==n)r++;
    return r;
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        scanf("%d",&n);
        if(n==0)printf("0\n");
        else if(n==1)printf("1\n");
        else s(n);
    }
    return 0;
}
