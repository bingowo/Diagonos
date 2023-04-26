#include <stdio.h>
#include <stdlib.h>
void fbnq1(int n,int*a,int*b)
{
if(n==1){return;}
if(n==2){b[0]=1;b[1]=0;return;}
if(n==3){b[0]=1;b[1]=0;return ;}
if(n==4){b[0]=2;b[1]=0;return;}
if(n==5){b[0]=2,b[1]=1;return;}
int c[2]={1,0},d[2]={0,1};
b[0]=2;b[1]=1;
for(int i=5;i<n;i++)
{a[0]=c[0]+d[0];
a[1]=c[1]+d[1];
c[0]=d[0];
c[1]=d[1];
d[0]=a[0];
d[1]=a[1];
b[0]+=a[0];
b[1]+=a[1];}
return;

}

int main()
{int a,n,m,x,t;
scanf("%d%d%d%d",&a,&n,&m,&x);
int b[2]={0},c[2]={0};
fbnq1(n,b,c);
t=(m-a*c[0])/c[1];
int d[2]={0},e[2]={0};
if(x!=n)
{fbnq1(x+1,d,e);
printf("%d",e[0]*a+e[1]*t);}
else printf("%d",m);
}
