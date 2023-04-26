#include <stdio.h>
#include <stdlib.h>
int a[550][550]={0};
int h[550][550]={0};
int z[550][550]={0};
int n,m,l;
char s[1000]={0};
int min(int a,int b)
{
    if(a>=b)return b;
    else return a;
}
void lujing(int i,int j)
{
    if(i==1&&j==1)return;
    if(i>=1 && j>=1 && z[i-1][j]>z[i][j-1]){s[l]='R';l--;lujing(i,j-1);}
    else if(i>=1 && j>=1 && z[i-1][j]<=z[i][j-1]){s[l]='D';l--;lujing(i-1,j);}

}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    l=(n-1)+(m-1)-1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++){scanf("%d",&a[i][j]);}

    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)z[i][j]=5000000;

    }
     for(i=1;i<=n;i++)
     {


        for(j=1;j<=m;j++)
        {
            if(i==1 &&j==1)z[i][j]=a[1][1];
            if(i>1)z[i][j]=min(z[i][j],a[i][j]+z[i-1][j]);
            if(j>1)z[i][j]=min(z[i][j],a[i][j]+z[i][j-1]);
        }
     }
     lujing(n,m);
     printf("%d\n",z[n][m]);
     printf("%s",s);
    return 0;
}
