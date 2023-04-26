#include <stdio.h>
#include <stdlib.h>
long long yanghui(long long m,long long n)
{
    long long a[42][42]={0};
    int i=0,j=0;
    for(i=0;i<40;i++){a[i][0]=1;a[i][i]=1;}
    for(i=0;i<=m;i++){for(j=1;j<i;j++){a[i][j]=a[i-1][j-1]+a[i-1][j];}}
    return a[m][n];
}
void jisuan(int h)
{
    long long m,n,j=0,i=0;
    scanf("%lld %lld",&m,&n);
    long long re=1;
    j=m/2;
    if(n>j)n=m-n;
    re=yanghui(m,n);
    printf("case #%d:\n",h);
    printf("%lld\n",re);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
    return 0;
}
