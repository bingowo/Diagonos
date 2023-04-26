#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int j,k,m,n,a[40000],T,i,p;
long g,t;
double s;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d",&n);
  s = 0;
for(k = 2;k <= n;k++)
s += log10(k);           //对数累加，确定n!的位数m
m = (int)s+1;
for(k = 1;k <=m;k++)
a[k] = 0;              //数组清零
a[1]=1;
g=0;
for(k = 2;k <= n;k++)
for(j = 1;j <= m;j++)
{
t = a[j] * k + g;         //数组累乘并进位
a[j] = t%10;
g = t/10; 
   }  
p=0;
while(a[p]==0)
p++;


 printf("case #%d:\n",i);
 printf("%d\n",p);
}
    
}