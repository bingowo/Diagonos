#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int main()
{ int n,m,i,j,k,s,ans,sum; int a[1000000];
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
{ scanf("%d",&a[i]);
}
qsort(a,n,sizeof(a[0]),cmp);
ans=0;
for(j=0;j<n-m+1;j++)
{ sum=0;
    for(k=j;k<j+m;k++)
{ sum+=(a[j]-a[k]);
}
if(sum<ans||ans==0) ans=sum;
}
printf("%d",ans);
}