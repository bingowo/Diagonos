#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
typedef long long ll;
typedef unsigned long long ull;

int pros;
ll a[10001],n;

int Get1(ull c){
    ull q=1;
    int sum=0;
    while(c){
        if(c&q) sum++;
        c>>=1;
    }
    return sum;
}

int Cmp(const ll* pa,const ll* pb){
    int a1=Get1(*pa);
    int b1=Get1(*pb);
    if(a1!=b1) return b1>a1;

    return *pa>*pb;
}

void Print(int cnt){
    printf("case #%d:\n",cnt);
    for(int i=0;i<n;i++)
        printf("%lld ",a[i]);
    printf("\n");
}

int main(){
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",a+i);
        qsort(a,n,sizeof(ll),Cmp);
        Print(cnt);
    }
    return 0;
}
