#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct data{
    int r;
    int h;
    long long int sy;
};

long long int cmp(const void *a, const void *b){
    struct data d1,d2;
    d1 = *((struct data*)a);
    d2 = *((struct data*)b);
    return (d2.sy - d1.sy); //降序排列表面积
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);//从n个里面挑选出m个
    struct data s[1001];
    for(int i = 0;i < n;i++){
        scanf("%d%d", &s[i].r,&s[i].h);
        s[i].sy = (long long int)s[i].r*s[i].h;
    }
    long long int ans = 0;
    for(int i = 0;i<n;i++){
        struct data s0[1001];
        int k = 0;
        for(int j = 0;j <n;j++){
            if(j!=i && s[j].r<=s[i].r) s0[k++] = s[j];
        }
        qsort(s0,k,sizeof(s0[0]),cmp);
        long long int area = 0;
        if(k != 0 && k >= m-1){
            for(int cnt = 0;cnt < m-1;cnt++) area += s0[cnt].sy;
        }
        ans = Max(ans, area *2 + (long long int)s[i].r*s[i].r + 2*s[i].sy);
    }
    printf("%lld\n",ans);

}
