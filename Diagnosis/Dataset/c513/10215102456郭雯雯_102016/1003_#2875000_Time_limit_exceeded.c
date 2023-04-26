#include<stdio.h>
#include<stdlib.h>
int num(int a)
{
    int n=0;
    while(a!=0){
        if(a&1==1)n++;
        a>>1;
    }
    return n;
}
int cmp(const void* a,const void* b){
    int t;
    int ia=*(int*)a,ib=*(int*)b;
    if(t=num(ib)-num(ib))return t;
    if(ia<ib)return -1;
    if(ia>ib)return 1;
}
void Sort(int *p, unsigned n){
    qsort(p,n,sizeof(*p),cmp); 
}
int main()
{ 
    int t,n,i,a[1000];  
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d",a+i);   Sort(a,n);
        for (i=0;i<n;i++) printf("%d%c",a[i],i!=n-1?' ':'\n');
        t--;
    }
    return 0;
}