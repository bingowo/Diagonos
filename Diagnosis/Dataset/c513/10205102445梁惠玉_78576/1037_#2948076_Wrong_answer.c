#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(long long*)b-*(long long*)a;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long a[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),cmp);
    long long result,temp=0;
    for(int i=1;i<m;i++)
    {
        temp+=a[0]-a[i];
    }
    result=temp;
    for(int i=1;i<=n-m;i++)
    {
        temp=temp-(a[i-1]-a[i])*(m-1)+a[i]-a[i+m-1];
        if(temp<result)
        {
            result=temp;
        }
    }
    printf("%lld\n",result);
    return 0;


}