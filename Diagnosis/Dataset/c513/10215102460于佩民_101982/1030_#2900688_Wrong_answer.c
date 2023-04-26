#include <stdio.h>
#include <stdlib.h>
long long int a[10001];
long long int cmp(const void*c, const void*d){
    long long int m,n,m1,n1;
    m=*(long long int*)c;
    n=*(long long int*)d;
    if(m<0) m=-m;
    if(n<0) n=-n;
    m1=m;
    n1=n;
    while(m>9) m/=10;
    while(n>9) n/=10;
    if(m!=n) return n-m;
    else if(m1>n1) return 1;
    else return -1;
}

int main(){
    int Num,num,now=0,i;
    scanf("%d",&Num);
    while(now<Num){
        scanf("%d",&num);
        for(i=0;i<num;i++) scanf("%d",&a[i]);
        qsort(a, num, sizeof(long long int), cmp);
        printf("case #");
        printf("%d:\n",now);
        for(i=0;i<num-1;i++) printf("%d ",a[i]);
        printf("%d\n",a[i]);
        now++;}
    return 0;
}