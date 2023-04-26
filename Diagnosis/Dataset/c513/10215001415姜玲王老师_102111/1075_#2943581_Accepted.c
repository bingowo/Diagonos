#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int n,m;
int a[200][200];
int c[200][200]={0};
char b[200][200][400]={0};
scanf("%d%d",&m,&n);
for(int i=0;i<m;i++)
{for(int j=0;j<n;j++)
{scanf("%d",&a[i][j]);}}
c[0][0]=a[0][0];
c[m-1][n-1]=a[m-1][n-1];
for(int i=0;i<m;i++)
{for(int j=0;j<n;j++)
{int temp1=0,temp2=0;
if(i==0&&j==0)
continue;
if(i==0)
    {c[i][j]=c[i][j-1]+a[i][j];strcpy(b[i][j],b[i][j-1]);b[i][j][i+j-1]='R';}
if(j==0)
{c[i][j]=c[i-1][j]+a[i][j];strcpy(b[i][j],b[i-1][j]);b[i][j][i+j-1]='D';}
if(i!=0&&j!=0)
{temp1=c[i-1][j]+a[i][j];temp2=c[i][j-1]+a[i][j];
if(temp1<temp2){c[i][j]=temp1;strcpy(b[i][j],b[i-1][j]);b[i][j][i+j-1]='D';}
else{c[i][j]=temp2;strcpy(b[i][j],b[i][j-1]);b[i][j][i+j-1]='R';}}
}
}
printf("%d\n",c[m-1][n-1]);
printf("%s",b[m-1][n-1]);
}
