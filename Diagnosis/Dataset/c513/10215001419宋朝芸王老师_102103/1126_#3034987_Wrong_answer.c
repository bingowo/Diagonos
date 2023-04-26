#include <stdio.h>
#include <stdlib.h>
#define N 10001
#define M 100000000

int cmp(const void *c, const void *d){
    long long a = *(long long*)c,
                b = *(long long*)d;
    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}

int main()
{
    int n;
    long long res = 0, temp;
    long long a[N] = {0};

    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lld",&temp);
        res ^= temp;
        a[i] = temp;
    }

    //case 1
    if(res != 0) {printf("-1\n");return 0;}

    //case other
    qsort(a,n,sizeof(a[0]),cmp);    //asc

    long long qian = 0, hou = 0;
    for(int i = 1; i < n; i++){
        hou += a[i];
        qian = hou / M;
        hou = hou % M;
    }
    if(qian == 0) printf("%lld\n",hou);
    else printf("%lld%07lld",qian,hou);


    return 0;
}
