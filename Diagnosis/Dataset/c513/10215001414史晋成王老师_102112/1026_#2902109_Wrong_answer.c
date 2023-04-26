#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{   int n,m;
    return *(const int*)a-*(const int*)b;
}
int main(){
int T,n,a[120000],i,j,ans=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
qsort(a,n,sizeof(int),cmp);
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
for(j=0;j<n;j+=2)
{ ans+=abs(a[j]-a[j+1]);
}
printf("%d",ans);
}