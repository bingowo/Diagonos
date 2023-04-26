#include <stdio.h>
#include <stdlib.h>
long long int a[10001];
int memory[10000];
long long int cmp(const void*c, const void*d){
    long long int m,n;
    m=*(long long int*)c;
    n=*(long long int*)d;
    long long int m1=m,n1=n;
    while(m>9) m/=10;
    while(n>9) n/=10;
    if(m!=n) return n-m;
    else if(m1>n1) return 1;
    else return -1;
}

int main(){
    int Num,num,now=0,i,count=0;
    scanf("%d",&Num);
    while(now<Num){
        scanf("%d",&num);
        for(i=0;i<num;i++) {
            scanf("%lld",&a[i]);
            if(a[i]<0) { a[i] = -a[i]; memory[count++]=i;}
        }
        qsort(a, num, sizeof(long long int), cmp);
        for(i=0;i<count;i++) a[memory[i]]=-a[memory[i]];
        printf("case #");
        printf("%d:\n",now);
        for(i=0;i<num-1;i++) printf("%lld ",a[i]);
        printf("%lld\n",a[i]);
        now++;
        count=0;}
    return 0;
}