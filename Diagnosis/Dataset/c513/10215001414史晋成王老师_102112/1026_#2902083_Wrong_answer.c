#include<stdio.h>
#include<stdlib.h>
int cmp(int a,int b)
{
    return a-b;
}
int main(){
int T,n,a[120000],i,j,ans=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",&a[i]);
}
qsort(a,n,sizeof(a[0]),cmp);
for(j=0;j<n;j+=2)
{ ans+=abs(a[j]-a[j+1]);
}
printf("%d",ans);
}