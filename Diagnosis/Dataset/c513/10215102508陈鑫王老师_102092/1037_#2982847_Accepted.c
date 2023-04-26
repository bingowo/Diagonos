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
    long long int temp=0;
    for(int i=1;i<m;i++)
    {
        temp+=ans[0]-ans[i];
    }
    long long int min=temp;
    for(int i=1;i<n-m+1;i++)
    {
        temp=temp-((m-1)*ans[i-1])+(m*ans[i])-ans[i+m-1];
        if(temp<min)
        {
            min=temp;
        }
    }
    printf("%lld",min);
    return 0;

}
