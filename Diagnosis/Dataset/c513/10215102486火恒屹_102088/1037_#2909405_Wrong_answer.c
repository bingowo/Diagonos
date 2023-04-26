#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return(*(long long*)a-*(long long*)b);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long num[1001]={0};
    for(int i=0;i<n;i++)
        scanf("%lld",&num[i]);
    qsort(num,n,sizeof(num[0]),cmp);
    long long sum=(m-1)*num[m-1];
    for(int i=0;i<m-1;i++)
        sum=sum-num[i];
    long long gap=0;
    int a=m-1;
    int b=0;
    for(int i=m;i<n;i++)
    {
        gap=(m-1)*(num[i]-num[a])-num[i-1]+num[b];
        if(gap<0)
        {sum=sum+gap; a=i; b=i-m+1;}
    }
    if(m==1) printf("0");
    else printf("%lld",sum);
    return 0;
}
