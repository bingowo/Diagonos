#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


void sort2(long long int*s,int m,long long int shu)
{
    int cmp2(const void*a1,const void*a2)
    {
        long long int a=*(long long int*)a1;
        long long int b=*(long long int*)a2;
        long long int c=llabs(shu-a),d=llabs(shu-b);
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
    long long int data[n-m+1];
    for(int k=0;k<n;k++)
    {
        data[k]=0;
        long long int shu=a[k];
        sort2(a,n,shu);
        for(int y=1;y<m;y++)
        {if(a[y]>shu) break;
        data[k]+=shu-a[y];}
        
    }
    long long datamin=data[0];
    for(int l=1;l<n-m+1;l++)
    if(data[l]<datamin) datamin=data[l];
    
    
    
    printf("%lld",datamin);
    return 0;
    
    
}