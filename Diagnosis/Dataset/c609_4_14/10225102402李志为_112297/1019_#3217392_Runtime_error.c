#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    long long num;
    int k;//k表示 位数
} N;
int cmp(const void*a,const void*b)
{
    if(((N*)a)->k==((N*)b)->k) return ((N*)a)->num-((N*)b)->num;
    else{
        return ((N*)b)->k-((N*)a)->k;
    }
}
N p[100000];
int main()
{
    long long t;
    int i=0;
    while(scanf("%lld",&p[i].num)!=EOF){
        t=p[i].num;
        while(t){
            p[i].k++;
            t=t/10;
        }
        i++;
    }
    qsort(p,i,sizeof(p[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%lld ",p[j].num);
    }
    return 0;
}
