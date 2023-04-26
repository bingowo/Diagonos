#include<stdio.h>
#include<stdlib.h>
int a[200][200]={0};
typedef struct
{int val; char dir;}Elem;

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<m;i++)
    {
        a[i][0]+=a[i-1][0];
    }
    for(int j=1;j<m;j++)
    {
        a[0][j]+=a[0][j-1];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i-1][j]<a[i][j-1])
            a[i][j]+=a[i-1][j];
            else a[i][j]+=a[i][j-1];
        }
    }
    printf("%lld\n",a[m-1][n-1]);

}
