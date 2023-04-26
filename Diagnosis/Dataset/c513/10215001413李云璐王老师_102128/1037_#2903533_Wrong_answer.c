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
        if(a>b) return 1;
        else if(a<b) return -1;
        else return 0;
    }
    qsort(s,m,sizeof(long long int),cmp1);
}//按数字大小排序

void sort2(long long int*s,int m,long long int shu)
{
    int cmp2(const void*a1,const void*a2)
    {
        long long int a=*(long long int*)a1;
        long long int b=*(long long int*)a2;
        long long int c=shu-a,d=shu-b;
        if(c>d) return 1;
        else if(c<d) return -1;
        else return 0;
        
    }
    qsort(s,m,sizeof(long long int),cmp2);
}//按差值大小排序
int main()
{
    int n,m;
    scanf("%d%d\n",&n,&m);
    long long int a[n];
    for(int i=0;i<n;i++)
    scanf("%lld",&a[i]);
    sort1(a,n);
    long long int data[n-m+1];
    for(int k=0;k<n-m+1;k++)
    {
        data[k]=0;
        long long int shu=a[k];
        sort2(a+k+1,n-k-1,shu);
        for(int y=k+1;y<k+m;y++)
        data[k]+=shu-a[y];
        sort1(a,n);
    }
    long long datamin=data[0];
    for(int l=1;l<n-m+1;l++)
    if(data[l]<datamin) datamin=data[l];
    
    
    
    printf("%lld",datamin);
    return 0;
    
    
}