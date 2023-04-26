#include<stdio.h>
#include<stdlib.h>
int num(long long int a)//判断数据a中1的个数
{
    int n=0,i=64;
    long long int m=1;
    while(i>0){
        if(a&m)n++;
        m=m<<1;
        i--;
    }
    return n;
}
int cmp(const void* a,const void* b)//qsort排序规则
{
    long long int ia=*(long long int*)a,ib=*(long long int*)b,t;
    if(t=num(ib)-num(ia))return t;
    if(ia>ib)return 1;
    if(ia<ib) return -1;
}
void Sort(long long int *p, unsigned n)//排序
{
    qsort(p,n,sizeof(*p),cmp); 
}
int main()
{ 
    int t,n,i,m=0;
    long long int a[10000];  
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%lld",a+i);   
        Sort(a,n);
        printf("case #%d:\n",m);
        for (i=0;i<n;i++) printf("%lld%c",a[i],i!=n-1?' ':'\n');
        t--;
        m++;
    }
    return 0;
}