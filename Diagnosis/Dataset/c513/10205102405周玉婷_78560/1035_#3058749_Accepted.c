#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;
typedef struct{
  lli r;
  lli h;
  lli rh;
} cyli;

int cmp1(const void* a, const void* b)//按r降序排列
{
    cyli* pa = (cyli*)a;
    cyli* pb = (cyli*)b;
    if((pa->r) < (pb->r)) return 1;
    return -1; 
}

int cmp2(const void* a, const void* b)//按2rh侧面积降序排列
{
    cyli* pa = (cyli*)a;
    cyli* pb = (cyli*)b;
    if((pa->rh) < (pb->rh)) return 1;
    return -1; 
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    cyli* p = (cyli*)malloc(sizeof(cyli)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld %lld", &p[i].r, &p[i].h);
        p[i].rh = 2*(p[i].r)*(p[i].h);
    }
    qsort(p, n, sizeof(cyli), cmp1);//按r降序排列

    lli sum=0, max=0, bottom=0;
    for(int i=0; i<=n-m; i++)//由大到小尝试各种半径为底面半径
    {
      bottom = p[i].r * p[i].r + p[i].rh;//底面圆柱的底面面积+侧面积
      sum += bottom;
      p[i].rh = 0;//底面圆柱侧面积作废
      qsort(p, n, sizeof(cyli), cmp2);//按侧面积大小降序排列
      for(int j=0; j<m-1; j++)//再选前m-1个,即可以放上去的侧面积较大的m-1个
      {
      sum += p[j].rh;
      }
      if(max < sum) max = sum;
      sum = 0;
      qsort(p, n, sizeof(cyli), cmp1);
    }
    printf("%lld\n", max);
    free(p);
    return 0;
}