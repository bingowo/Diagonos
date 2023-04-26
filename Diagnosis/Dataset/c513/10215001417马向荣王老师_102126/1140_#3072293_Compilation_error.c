#include<stdio.h>
#include<string.h>
int cop(int *a,int *b)
{
    int c[100];
    int k=0;
    for(int i=1;i<a[0];i++)
    {
        for(int j=1;j<b[0];j++)
        {
            if(a[i]==b[j])
            {
                c[k]=a[i];
                k++;
            }
        }
    }
    return c;
}
int main()
{
    int n,m,k=1,c;
    scanf("%d\n",&n);
    int d[n][101],p[101]={0};
    for(int k=0;k<n;k++)
    {
        scanf("%d ",&d[k][0]);
        for(int j=1;j<=d[k][0];j++)
        {
            scanf("%d ",&d[k][j]);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        d[i]=cop(d[i+1],d[i]);
    }
    for(int i=1;i<d[n-1][0];i++)
    {
        printf("%d ",d[n-1][i]);
    }
    return 0;
}