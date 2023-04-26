#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    long long pa=*(long long*)a,pb=*(long long*)b;
    if(pa!=pb) return pa>pb?1:-1;
    else return -1;
}

int cmp2(const void *a,const void *b)
{
    long long pa=*(long long*)a,pb=*(long long*)b;
    if(pa!=pb) return pa<pb?1:-1;
    else return -1;
}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;scanf("%d",&n);
        long long a[n],b[n];
        for(int j=0;j<n;j++){scanf("%lld",&a[j]);}
        for(int j=0;j<n;j++){scanf("%lld",&b[j]);}
        qsort(a,n,sizeof(long long),cmp1);
        qsort(b,n,sizeof(long long),cmp2);
        long long Sum=0;
        for(int j=0;j<n;j++){
            Sum+=a[j]*b[j];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",Sum);

    }


	return 0;
}
