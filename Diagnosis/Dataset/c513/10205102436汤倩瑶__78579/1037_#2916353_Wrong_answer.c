#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    long long int p1= *((long long int *)a);
    long long int p2=*((long long int *)b);
    if(p1>p2)return 1;
    else return -1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long int *a=(long long int *)malloc(sizeof(long long int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);

       long long ans=0;
       for(int j=0;j<m-1;j++)
    ans+=a[m-1]-a[m-j-2];
    long long int tmp;
    for(int i=m;i<n;i++)
    {tmp=ans+a[i-m]-(m+1)*a[i-1]+m*a[i];
        if(tmp<ans)ans=tmp;
    }
    
    


    printf("%lld",ans);


}
