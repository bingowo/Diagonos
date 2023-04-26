#include<stdio.h>
#define N 100
int main()
{
char c;
int n,a[100],b[100],i,j,k = 0,flag = 1,t;
scanf("%d",&c);
while(scanf("%d",&a[i]))
n++;
for(i = 0; i < N; i++)
{
flag = 1;
for(j = 0; j < i; j++)
if(a[i] == b[j])
flag = 0;
if(flag)
{
b[k] = a[i];
k++;
}
}
if(c=='A')
{
for(i = 0; i < k-1; i++)
{
n=i;
for(j=i+1;j<k;j++)
if(b[j]<b[n])
n=j;
t=b[n];b[n]=b[i];b[i]=t;
}
}
if(c=='D')
{
for(i = 0; i < k-1; i++)
{
n=i;
for(j=i+1;j<k;j++)
if(b[j]>b[n])
n=j;
t=b[n];b[n]=b[i];b[i]=t;
}
}

for(i = 0; i < k; i++)
printf("%-4d",b[i]);
}