#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int n,m;
int a[200][200];
int c[200][200];
char b[200][200][400]={0};
scanf("%d%d",&m,&n);
for(int i=0;i<n;i++)
{for(int j=0;j<m;j++)
{scanf("%d",&a[i][j]);}}
c[0][0]=a[0][0];
c[n-1][m-1]=a[n-1][m-1];
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{int temp1,temp2;
if(i==0&&j==0)
continue;
if(i==0)
    {c[i][j]=c[i][j-1]+a[i][j];strcpy(b[i][j],b[i][j-1]);b[i][j][i+j-3]='D';}
if(j==0)
{c[i][j]=c[i-1][j]+a[i][j];strcpy(b[i][j],b[i-1][j]);b[i][j][i+j-3]='R';}
if(i!=0&&j!=0)
{temp1=c[i-1][j]+a[i][j];temp2=c[i][j-1]+a[i][j];
if(temp1>temp2){c[i][j]=temp1;strcpy(b[i][j],b[i-1][j]);b[i][j][i+j-3]='R';}
else{c[i][j]=temp2;strcpy(b[i][j],b[i][j-1]);b[i][j][i+j-3]='D';}}
}
}
printf("%d\n",c[n-1][m-1]);
printf("%s",b[n-1][m-1]);
}
