#include<cstdio>
#include<climits>
#include<bits/stdc++.h>
#define M 100+2// 10 for s(i)，2 for s(e) and s(m+1)
#define N 100
#define INT_MAX 21474483647
using namespace std;
int C(int L,int R,int (*a)[N],int n)
{ int r,i,j,min;
    for(r=j=0;j<n;j++)
        { for (min=INT_MAX,i=L;i<=R;i++) if (a[i][j]<min) min=a[i][j];r+=min;}
    return r;
}
int E(int L,int R,int (*c)[N])
{int i,t;const int e[M][M];
    if (L<R&&!e[L][R])
    for (e[L][R]=INT_MAX,i=L;i<R;i++)
   if ((t=E(L,i,c)+E(i+1,R,c)+2*(c[L][i]+c[i+1][R]-2*c[L][R]))<e[L][R]) e[L][R]=t;
  return  e[L][R];
}

int main()
{int i,j,m,n,a[M][N]={0},c[M][N]={0}; scanf("%d%d",&m,&n);
    for (i=1;i<=m;i++) for (j=0;j<n;j++)scanf("%d",&a[i][j]);
    for (i=1;i<=m;i++) for (j=i;j<=m;j++)c[i][j]=C(i,j,a,n);
    printf("%d\n",E(1,m+1,c)); return 0;




}
