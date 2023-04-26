#include <stdio.h>
#include <limits.h> //for INT MAX
// 100 for s(i)，2 for s(e) and s(m+1)#define M100+2
#define N1094
int C(int L,int R,int (*a)[N],int n)6-fint r,i,j,min;
for (r=j=;j<n;j++){ for (min=INT_MAX,i=L;i<=R;i++) if (a[i][j]<min) min=a[i][j]; r+=min;}return r;
}
int E(int L,int R,int (*c)IN])[int i,t; static int e[M][M];if (L<R&&!erLITRT)for (erL]TR]=INT MAX,i=L;i<R;i++)if ((t=E(L,i,c)+E(i+1,R,c)+2*(c[L][i]+c[i+1][R]-2*C[L][R]))<e[L][R]) e[L][R]=t;e[L][R];return
int main()int i,j,m,n,a[M][N]={O},c[M][N]=(e); scanf("%d%d",&m,&n);for (i=1;i<=m;i++) for (j=;j<n;j++)scanf("%d",&aliljT);for (i=1;i<=m;i++) for (j=i;j<=m;j++)c[il[j]=C(i,j,a,n);printf("%d\n",E(1,m+1,c)); return @;