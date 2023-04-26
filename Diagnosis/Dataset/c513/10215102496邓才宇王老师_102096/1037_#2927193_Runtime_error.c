#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2)
{
    long long int* a=p1;
    long long int* b=p2;
    if(*a>*b) return -1;
    else if(*a<*b) return 1;
    else return 0;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int s[2000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i]);
    }
    qsort(s,n,sizeof(long long int),cmp);
     long long int ans[2000]={0};
     for(int k=0;k<m;k++) ans[0]=ans[0]+s[0]-s[k];
     for(int j=1;j<n-m+1;j++)
     {
         ans[j]=ans[j-1]-s[j-1]*(m-1)+s[j]*m-s[j+m-1];
     }
     qsort(ans,n-m+1,sizeof(long long int),cmp);
     printf("%lld",ans[n-m]);
}
