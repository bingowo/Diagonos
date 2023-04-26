#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b)
{ long long int x,y;
x=*(long long int*)a;
y= *(long long int*)b;
if(y>x) return 1;
else return -1;
}
int main()
{ int n,m,i,j,k,s; long long int a[1000000]; long long int ans,sum;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
{ scanf("%lld",&a[i]);
}
a[n]=0;
qsort(a,n,sizeof(a[0]),cmp);
ans=0;
for(k=0;k<m;k++)
ans+=a[0]-a[k]; sum=ans;
if(n>m)
{
for(j=1;j<n-m+1;j++)
{ sum=sum-m*(a[j-1]-a[j])+a[j-1]-a[j+m-1];
if(sum<ans||ans==0) ans=sum;
}
}
printf("%lld",ans);
}