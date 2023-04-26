#include<stdio.h>
#include<stdlib.h>
int num(int a)
{
    int n=0;
    while(a!=0){
        if(a&1==1)n++;
        a=a>>1;
    }
    return n;
}
int cmp(const void* a,const void* b){
    int ia=*(int*)a,ib=*(int*)b,t;
    if(t=num(ib)-num(ia))return t;
    if(ia>ib)return 1;
    if(ia<ib) return -1;
}
void Sort(int *p, unsigned n){
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
        for (i=0;i<n;i++) printf("%d%c",a[i],i!=n-1?' ':'\n');
        t--;
        m++;
    }
    return 0;
}