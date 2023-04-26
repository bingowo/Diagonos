#include<stdio.h>
#include<stdlib.h>
int number(unsigned a){
    int num=0;
    while(a>0){
        if(a&1==1)num++;
        a=a>>1;
    }
    return num;
}
int cmp(const void*a,const void*b){
    int t;
    unsigned ia=*(unsigned*)a,ib=*(unsigned*)b;
    if(t=number(ib)-number(ia))return t;
    if(ia>ib)return 1;
    if(ia<ib) return -1;
}
void Sort(unsigned *p, unsigned n){
    qsort(p,n,sizeof(*p),cmp); 
}
int main()
{ 
    unsigned n,i,a[1000];  scanf("%u",&n);
    for (i=0;i<n;i++) scanf("%u",a+i);   Sort(a,n);
    for (i=0;i<n;i++) printf("%u%c",a[i],i!=n-1?' ':'\n');
    return 0;
}