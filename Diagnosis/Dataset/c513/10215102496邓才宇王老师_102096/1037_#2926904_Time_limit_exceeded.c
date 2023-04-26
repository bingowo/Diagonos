#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2)
{
    long long int* a=p1;
    long long int* b=p2;
    if(*a>*b) return 1;
    else if(*a<*b) return -1;
    else return 0;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int s[2000000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i]);
    }
    qsort(s,n,sizeof(long long int),cmp);
     long long int ans[2000000]={0};
     for(int j=0;j<n-m+1;j++)
     {
         for(int k=j;k<m+j;k++)
         {
             ans[j]=ans[j]+s[m+j-1]-s[k];
         }
     }
     qsort(ans,n-m+1,sizeof(long long int),cmp);
     printf("%lld",ans[0]);
}
