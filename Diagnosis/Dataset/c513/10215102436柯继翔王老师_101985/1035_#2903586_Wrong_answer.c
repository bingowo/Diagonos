#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    long long *a1 = (long long*)a,*b1 = (long long*)b;
    if(a1[2] == b1[2])return a1[0] > b1[0]?-1:1;
    else return a1[2] > b1[2]?-1:1;
}

int main()
{
    int m,n;
    long long a[1000][3];
    scanf("%d%d",&m,&n);
    for(int i = 0;i < m;i++){
        scanf("%lld%lld",&a[i][0],&a[i][1]);
        a[i][2] = a[i][0] * a[i][1];
    }
    qsort(a,m,sizeof(a[0]),cmp);
    int x = 0,y = 0;
    for(int i = 0;i < n;i++){
        x += 2 * a[i][0] * a[i][1];
        if(a[i][0] > y)y = a[i][0];
    }
    x += y * y;
    printf("%lld",x);
    return 0;
}
