#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

struct data{
    int r;
    int h;
    long long sy;
};

int cmp(const void *a, const void *b){
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
        s[i].sy = (long long)s[i].r*s[i].h;//输入半径和长，顺便算出一点面积
    }
    long long ans = 0;
    for(int i = 0;i<n;i++){
        struct data s0[1001];
        int k = 0;
        for(int j = 0;j <n;j++){
            if(j!=i && s[j].r<=s[i].r) s0[k++] = s[j];
        }//选出半径比某一个i小的圆柱
        //按照表面积大小进行降序排序
        qsort(s0,k,sizeof(s0[0]),cmp);
        //暂定最大面积为0
        long long area = 0;
        //如果k不为0，也就是这不是最小半径的圆柱，并且选出的圆柱个数大于m
        if(k != 0 && k >= m-1){
            for(int cnt = 0;cnt < m-1;cnt++) area += s0[cnt].sy;//其余圆柱的侧面积
        }
        else{

        }
        ans = ans > ((2*area + (long long)s[i].r*s[i].r + 2*s[i].sy))?ans:(area *2 + (long long)s[i].r*s[i].r + 2*s[i].sy);
    }
    printf("%lld",ans);
}