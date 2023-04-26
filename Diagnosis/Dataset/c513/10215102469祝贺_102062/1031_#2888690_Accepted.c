#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//快排有风险，使用需谨慎
int cmp(const void*a, const void*b){
    return *((int*)a)-*((int*)b);
}
int main()
{
    long long n;scanf("%lld",&n);
    for(int m=0;m<n;m++){
        long long ans=0;
        int d;scanf("%d",&d);
        int a1[d],a2[d];
        for(int i=0;i<d;i++)scanf("%d",&a1[i]);
        for(int i=0;i<d;i++)scanf("%d",&a2[i]);

        qsort(a1,d,sizeof(int),cmp);
        qsort(a2,d,sizeof(int),cmp);
        for(int i=0;i<d;i++){
            ans+=a1[i]*a2[d-1-i];
        }
        printf("case #%d:\n",m);
        printf("%lld\n",ans);
    }
}
