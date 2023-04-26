#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int a[201][201];
typedef struct
{
    long long int n;
    char c;
} list;
int main()
{
    int id=0,m,n;
    list b[201][201];
    char s[400];
    scanf("%d %d",&m,&n);
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    b[1][1].n=a[1][1];
    b[1][1].c='1';
    for(int i=2; i<=n; i++)
    {
        b[1][i].n=b[1][i-1].n+a[1][i];
        b[1][i].c='R';
    }
    for(int i=2; i<=m; i++)
    {
        b[i][1].n=b[i-1][1].n+a[i][1];
        b[i][1].c='D';
    }
    for(int i=2; i<=m; i++)
        for(int j=2; j<=n; j++)
        {
            if(b[i-1][j].n>b[i][j-1].n)
            {
                b[i][j].c='R';
                b[i][j].n=b[i][j-1].n+a[i][j];
            }
            else
            {
                b[i][j].c='D';
                b[i][j].n=b[i-1][j].n+a[i][j];
            }
        }
    int len=m+n-2,i=m,j=n;
    while(i>1||j>1)
    {
        if(b[i][j].c=='R')
        {
            j--;
            s[id++]='R';
        }
        else
        {
            i--;
            s[id++]='D';
        }
    }

    printf("%lld\n",b[m][n].n);
    for(int j=len-1; j>=0; j--)
        printf("%c",s[j]);
    return 0;
}
