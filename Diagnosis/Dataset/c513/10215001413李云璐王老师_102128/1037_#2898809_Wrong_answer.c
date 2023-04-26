#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void sort(long long int*s,int m)
{
    int cmp(const void*a1,const void*a2)
    {
        long long int a=*(long long int*)a1;
        long long int b=*(long long int*)a2;
        if(a>b) return 1;
        if(a<b) return -1;
    }
    qsort(s,m,sizeof(long long int),cmp);
}
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    long long int a[n];
    for(int i=0;i<n;i++)
    scanf("%lld",&a[i]);
    sort(a,n);
    long long int b[m];
    for(int l=0;l<m;l++)
    b[l]=a[l];
    long long int max=b[m-1],data=0;
    for(int k=0;k<m-1;k++)
    data+=max-b[k];
    printf("%lld",data);
    return 0;
    
    
}