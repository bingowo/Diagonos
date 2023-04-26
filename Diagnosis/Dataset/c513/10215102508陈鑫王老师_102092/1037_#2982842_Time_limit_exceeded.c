#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    long long int x=*(long long int*)a;
    long long int y=*(long long int*)b;
    return x>y?-1:1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int ans[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&ans[i]);
    }
    qsort(ans,n,sizeof(long long int),cmp);
    long long int minret=0;
    for(int i=1;i<m;i++)
    {
        minret+=ans[0]-ans[i];
    }
    for(int i=1;i<n-m+1;i++)
    {
        long long int ret=0,k=ans[i];
        int temp=1;
        for(int j=i+1;j<n&&temp<m;j++)
        {
            ret+=k-ans[j];
            temp++;
        }
        if(temp==m)
        {
            minret=minret<ret?minret:ret;
        }
    }
    printf("%lld",minret);
    return 0;

}