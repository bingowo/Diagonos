#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(long long*)a > *(long long*)b?-1:1;
}

long long a[1000000];

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)
        scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    long long min = 0;
    for(int i = 1;i < m;i++){
        min += a[0] - a[i];
    }
    for(int i = 1;i < n - m + 1;i++){
        long long x = 0;
        for(int j = i + 1;j < i + m;j++){
            x += a[i] - a[j];
        }
        if(i == 0)min = x;
        if(x < min)min = x;
    }
    printf("%lld",min);
    return 0;
}
