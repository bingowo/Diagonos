#include<stdio.h>
#include<stdlib.h>
struct data
{
    int a;
    char s;
};
long long int C(int n,int m)
{
    long long int t=1;
    for(int i=1;i<m+1;i++)
    {
        t=t*(n-i+1)/i;
    }
    return t;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    struct data p[C(n+m-2,m-1)];
    
}