#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a,const void*b)
{ return *(int *a)-*(int *b);
}
int main()
{ int m,n,a[10000]={0},b[10000]={0},c[10000]={0}i,j,p,q,f,t;
scanf("%d",&m);
for(i=0;i<m;i++)
scanf("%d",&a[i]);
scanf("%d",&n);
for(j=0;j<n;j++)
scanf("%d",&b[j]);
f=0;
for(p=0;p<m;p++)
{ for(q=0;q<n;q++)
  {if(a[p]==b[q]) {c[p]=b[q];b[q]=9999;f++;}}
}
qsort(b,n,sizeof(int),cmp);
for(p=0;p<f;p++)
printf("%d ",c[p]);
t=0;
while(b[t]!=9999)
{printf("%d ",b[t]);t++;}
}