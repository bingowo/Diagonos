#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int judge(int n,int* a)
{
    int k,n1,n2,i;
    n1=n;n2=n;
    for(k=0;n1;k++)//表示n是k位数
        n1=n1/10;
    int m=0;
    for(i=0;i<k;i++)
    {
        m=10*m+n2%10;
        n2=n2/10;
    }
    if(n==m)
        return n;
    else
    {
        a[0]++;
        judge(n+m,a);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int m;
    int a[1]={1};
    m=judge(n,a);
    printf("%d %d",a[0],m);
}