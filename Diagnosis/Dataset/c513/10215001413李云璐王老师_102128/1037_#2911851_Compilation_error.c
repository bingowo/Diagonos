#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void sort1(long long int*s,int m)
{
    int cmp1(const void*a1,const void*a2)
    {
        long long int a=*(long long int*)a1;
        long long int b=*(long long int*)a2;
        if(b>a) return 1;
        if(b<a) return -1;
        
    }
    qsort(s,m,sizeof(long long int),cmp1);
}//按数字大小排序

long long int pick(long long int*s,int n,int m)
{
    
    if(n==m)
    {
        long long int ans=0;
        for(int i=1;i<n;i++) ans+=s[0]-s[i];
        return ans;
    }
   
    else
    {
        long long int ans=0;
        for(int i=1;i<m;i++) ans+=s[0]-s[i];
        long long int min=ans;
        for(int k=1;k<=n-m;k++)
       { ans=ans+(s[k]-s[k-1])*(m-1)+s[k]-s[k+m-1];
       min=(min>ans)?ans:min;}
       return min;
    }
    
}
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    long long int a[n];
    for(int i=0;i<n;i++)
    scanf("%lld",&a[i]);
    sort(a,n);
    long long int l;
    l=pick(a,n,m);
    printf("%lld",l);
    return 0;
    
    
}