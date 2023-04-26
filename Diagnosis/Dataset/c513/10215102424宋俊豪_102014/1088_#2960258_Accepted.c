#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void find(long long int (*a)[42])
{
  for(int i=0;i<42;i++)
  {
      a[i][0]=1;
      a[i][i]=1;
  }
  for(int i=2;i<=40;i++)
    for(int j=1;j<i;j++)
  {
      a[i][j]=a[i-1][j-1]+a[i-1][j];
  }
}
int main()
{
    int n;long long a[42][42]={0};
    find(a);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        printf("case #%d:\n%lld\n",i,a[m][n]);
    }
    return 0;
}
